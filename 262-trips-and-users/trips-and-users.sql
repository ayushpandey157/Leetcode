WITH trips_not_banned_users AS (
    SELECT
        t.id,
        t.client_id,
        t.driver_id,
        t.request_at,
        t.status
    FROM Trips t
    JOIN Users d
    ON d.users_id = t.driver_id
    JOIN Users c
    ON c.users_id = t.client_id
    WHERE
        c.banned = 'No'
            AND
        d.banned = 'No'
),
dates_with_atleast_one_trip AS (
    SELECT request_at
    FROM trips_not_banned_users
    WHERE request_at BETWEEN "2013-10-01" AND "2013-10-03"
    GROUP BY request_at
    HAVING COUNT(*) > 0
),
required_trips AS (
    SELECT *
    FROM trips_not_banned_users
    WHERE request_at IN (SELECT request_at FROM dates_with_atleast_one_trip)
)
SELECT
    request_at AS Day,
    ROUND(
    COUNT(
        CASE WHEN
            status IN ('cancelled_by_client', 'cancelled_by_driver') THEN 1
        END
    ) * 1.0 / COUNT(*)
    , 2) AS "Cancellation Rate"
FROM required_trips
GROUP BY request_at;