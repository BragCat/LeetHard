SELECT D.Name AS Department, E.Name AS Employee, E.Salary AS Salary
    FROM Department AS D, Employee AS E
    WHERE D.Id = E.DepartmentId 
        AND (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE DepartmentId = D.Id AND Salary > E.Salary) < 3
    ORDER BY D.Name, E.Salary DESC
