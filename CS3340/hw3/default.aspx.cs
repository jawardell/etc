using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _default : System.Web.UI.Page
{
    //need one event per session
    Event event1;
   
    //need to add different tickets to the same event
    protected void Page_Load(object sender, EventArgs e)
    {
        event1 = (Event)Session["event1"];
        Label2.Text = "";
        if (!Page.IsPostBack)
        {
            ticketArena.Visible = !ticketArena.Visible;
            if (!(event1 == null))
            {
                ListItem[] seats = buildSeatList(event1);
                DropDownList1.DataSource = seats;
                DropDownList1.DataBind();
            }
        }
            
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (true) { ticketArena.Visible = !ticketArena.Visible; }
        event1 = new Event(TextBox1.Text, Int32.Parse(TextBox2.Text), Int32.Parse(TextBox3.Text));
        Session["event1"] = event1;
        TextBox6.Text = "Session[event1] : " + ((Event)Session["event1"]).toString() + "\n\nEvent1: \n" + event1.toString();
        ListItem[] seats = buildSeatList(event1);
        DropDownList1.DataSource = seats;
        DropDownList1.DataBind();
        Label1.Text = event1.getAvailableSeatsList().Count.ToString();
    }
    private ListItem[] buildSeatList(Event event1)
    {
        int size = (event1.getAvailableSeatsList().Count);
        int start = event1.getSeatStart();
        ListItem[] templist = new ListItem[size];
        for (int i = 0; i < size; i++)
        {
            templist[i] = new ListItem((start++).ToString());
        }
        return templist;
    }
    private ListItem[] buildSeatList2(Event event1) {
        int size = (event1.getAvailableSeatsList().Count);
        ListItem[] templist = new ListItem[size];
        for (int i = 0; i < size; i++)
        {
            templist[i] = new ListItem((event1.getAvailableSeatsList()[i]).ToString());
        }
        return templist;
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Ticket ticket = new Ticket(TextBox4.Text, Int32.Parse(TextBox5.Text), Int32.Parse(DropDownList1.SelectedItem.ToString()));
        if (event1.getAvailableSeatsList().Count == 0) {
            Label2.Text = "No seats are available.";
            return;
        }
        if (event1.hasTicket(ticket)) {
            Label2.Text = "A ticket has already been purchased using that name.";
            return;
        }
        if (event1.seatTaken(ticket)) {
            Label2.Text = "This seat has already been chosen.";
            return;
        }
        event1.addTicket(ticket);
        TextBox6.Text = "Session[event1] : " + ((Event)Session["event1"]).toString() + "\n\nEvent1: \n" + event1.toString();
        ListItem[] seats = buildSeatList2(event1);
        DropDownList1.DataSource = seats;
        DropDownList1.DataBind();
        Label1.Text = event1.getAvailableSeatsList().Count.ToString();
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        Response.Redirect("eventSummary.aspx");
    }
}