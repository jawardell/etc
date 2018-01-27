using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text;

public partial class _default : System.Web.UI.Page
{

    List<Account> accounts = new List<Account>();
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["accounts"] == null)
        {
            accounts = new List<Account>();
        }
        else
        {
            accounts = (List<Account>)Session["accounts"];
        }
        //testAccountClass();

    }

    private void testAccountClass()
    {
        Account a = new Account(100.0);
        accounts.Add(a);
        a = new Account(50.0);
        accounts.Add(a);
        a = new Account(400.0);
        accounts.Add(a);
        displayAccounts();
    }
    private void displayAccounts()
    {
        StringBuilder builder = new StringBuilder();
        foreach (Account a in accounts)
        {
            builder.Append(a.ToString() + Environment.NewLine);
        }
        txtMsg.Text = builder.ToString();
    }

    protected void btnAddAccount_Click(object sender, EventArgs e)
    {
        double bal = Convert.ToDouble(txtBalance.Text);
        Account a = new Account(bal);
        accounts.Add(a);
        displayAccounts();
        txtBalance.Text = "";
        txtBalance.Focus();
        Session.Add("accounts", accounts);
        lblNumAccounts.Text = accounts.Count.ToString();

    }
    protected void btnClearAccounts_Click(object sender, EventArgs e)
    {
        Session.Clear();
        txtMsg.Text = "";
        lblNumAccounts.Text = "0";
    }
    protected void btnSummary_Click(object sender, EventArgs e)
    {
        Response.Redirect("Summary.aspx");
    }
}