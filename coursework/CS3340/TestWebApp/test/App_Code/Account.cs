using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Text;

/// <summary>
/// Summary description for Account
/// </summary>
public class Account
{

    // Field
    private double balance;
    // Constructor
    public Account(double balance)
    {
        this.balance = balance;
    }
    // Property
    public double Balance
    {
        get
        {
            return balance;
        }
        set
        {
            if (value >= 0.0)
                balance = value;
            else
                balance = 0.0;
        }
    }
    public override string ToString()
    {
        return "Bal=" + Balance.ToString("C");
    }

}