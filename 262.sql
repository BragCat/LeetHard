SELECT T.Request_at AS 'Day', ROUND(SUM(CASE WHEN T.Status LIKE 'cancelled%' THEN 1 ELSE 0 END) / COUNT(*), 2) AS 'Cancellation Rate'
    FROM Trips AS T, Users AS U 
    WHERE T.Client_Id = U.Users_Id AND U.Banned = 'No'
        AND T.Request_at BETWEEN '2013-10-01' AND '2013-10-03' 
    GROUP BY T.Request_at
