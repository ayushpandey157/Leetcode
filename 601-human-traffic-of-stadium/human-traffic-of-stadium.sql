WITH filtered AS (
    SELECT id, visit_date, people
    FROM stadium
    WHERE people >= 100
),
tagged AS (
    SELECT 
        id, visit_date, people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS grp
    FROM (
        SELECT *,
               ROW_NUMBER() OVER (ORDER BY id) AS rn
        FROM filtered
    ) AS numbered
),
valid_rows AS (
    SELECT id, visit_date, people
    FROM tagged
    WHERE grp IN (
        SELECT grp
        FROM tagged
        GROUP BY grp
        HAVING COUNT(*) >= 3
    )
)
SELECT id, visit_date, people
FROM valid_rows
ORDER BY visit_date;