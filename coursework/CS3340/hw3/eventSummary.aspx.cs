using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class eventSummary : System.Web.UI.Page
{
    Event event1;
    
    protected void Page_Load(object sender, EventArgs e)
    {
        event1 = (Event)Session["event1"];
        Label1.Text = event1.getName();
        TextBox1.Text = event1.toString();
        ListItem[] li = buildHolderList(event1);
        DropDownList1.DataSource = li;
        DropDownList1.DataBind();
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Redirect("default.aspx");
    }

    public ListItem[] buildHolderList(Event event1) {
        int size = event1.getTickets().Count;
        ArrayList tickets = event1.getTickets();
        ListItem[] tempList = new ListItem[size];
        
        for (int i = 0; i < size; i++) {
            tempList[i] = new ListItem(((Ticket)tickets[i]).getName());
        }
            return tempList;
    }
    protected void Button1_Click1(object sender, EventArgs e)
    {
        TextBox1.Text = event1.toString();
        ListItem[] li = buildHolderList(event1);
        DropDownList1.DataSource = li;
        DropDownList1.DataBind();

    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        String holderName = DropDownList1.SelectedItem.ToString();
        //need ticket constructor for just name
        //need get ticket method for event class

        //make ticket using holder name
        //grab ticket from event
        //remove ticket from event


        Ticket ticket = event1.getTicket(holderName);
        event1.removeTicket(ticket);
        TextBox1.Text = event1.toString();
        ListItem[] li = buildHolderList(event1);
        DropDownList1.DataSource = li;
        DropDownList1.DataBind();
    }
}