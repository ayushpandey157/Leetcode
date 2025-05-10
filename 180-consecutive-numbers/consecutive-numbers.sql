# Write your MySQL query statement below
SELECT l1.num AS ConsecutiveNums 
FROM Logs l1
LEFT JOIN Logs l2
    ON l1.num = l2.num
    AND l2.id - l1.id = 1
    LEFT JOIN Logs l3
        ON l2.num = l3.num
        AND l3.id - l2.id = 1
WHERE l2.id IS NOT NULL AND l3.id IS NOT NULL
GROUP BY l1.num