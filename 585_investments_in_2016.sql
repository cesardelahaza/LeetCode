# Write your MySQL query statement below
WITH previous_tiv_2015 AS (
    SELECT *
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(tiv_2015) > 1
), different_locations AS (
    SELECT *
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
)

SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM different_locations
WHERE tiv_2015 IN (SELECT tiv_2015 FROM previous_tiv_2015);
