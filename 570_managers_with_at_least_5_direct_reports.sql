# Write your MySQL query statement below
WITH names AS (
    SELECT m.name, COUNT(*) AS quants, m.id
    FROM Employee e LEFT JOIN Employee m ON e.managerId = m.id
    WHERE m.id IS NOT NULL
    GROUP BY e.managerId
)
SELECT name FROM names WHERE quants >= 5;
