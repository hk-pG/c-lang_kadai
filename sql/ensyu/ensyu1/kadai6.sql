-- 1

SELECT date, direction, point
FROM traffic
WHERE
    date = '2022-09-13'
   or date = '2022-09-14'
	
-- 2

SELECT date, direction, point
FROM traffic
WHERE date >= '2022-09-13' AND
date <= '2022-09-14'