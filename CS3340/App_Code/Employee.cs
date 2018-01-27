using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

public class Employee
{
    public int ID
    {
        get;
        set;
    }
    public String LastName
    {
        get;
        set;
    }
    public String FirstName
    {
        get;
        set;
    }
    public Employee(int ID, String FirstName, String LastName)
    {
        this.ID = ID;
        this.LastName = LastName;
        this.FirstName = FirstName;
    }
    public override string ToString()
    {
        String msg = String.Format("Employee {0}, {1} {2}", ID, FirstName, LastName);
        return msg;
    }
}