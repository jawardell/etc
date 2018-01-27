using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Summary : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        List<Account> accounts = (List<Account>)Session["accounts"];
        if (accounts == null)
        {
            txtSummary.Text = "No accounts";
        }
        else
        {
            displayAccounts(accounts);
        }
    }


    protected void btnAddAccount_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default.aspx");
    }

    protected void btnStartOver_Click(object sender, EventArgs e)
    {
        Session.Clear();
        Response.Redirect("Default.aspx");
    }
    private double totalBalance(List<Account> accounts)
    {
        double total = 0.0;
        foreach (Account a in accounts)
            total += a.Balance;
        return total;
    }

    private void displayAccounts(List<Account> accounts)
    {
        int count = 0;
        double total = totalBalance(accounts);
        StringBuilder builder = new StringBuilder();

        builder.Append("Num accounts : " + accounts.Count + Environment.NewLine);
        builder.Append("Total balance: " + total.ToString("C") + Environment.NewLine);
        builder.Append(Environment.NewLine);
        foreach (Account a in accounts)
        {
            count++;
            builder.Append(count + ". " + a.ToString() + Environment.NewLine);
        }
        txtSummary.Text = builder.ToString();
    }

}