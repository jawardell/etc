using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if(!Page.IsPostBack)
        {
            ListItem[] availableCourses = buildAvailableCourseList();
            lbxAvailableClasses.DataSource = availableCourses;
            lbxAvailableClasses.DataTextField = "Text";
            lbxAvailableClasses.DataValueField = "Value";
            lbxAvailableClasses.DataBind();
        }
    }

    private ListItem[] buildAvailableCourseList()
    {
        ListItem[] templist = {
                                  new ListItem("CS 1301-4", "CS 1301-4"),
                                  new ListItem("CS 1302-4", "CS 1302-4"),
                                  new ListItem("CS 1303-4", "CS 1303-4"),
                                  new ListItem("CS 2202-2", "CS 2202-2"),
                                  new ListItem("CS 2224-2", "CS 2224-2"),
                                  new ListItem("CS 3300-3", "CS 3300-3"),
                                  new ListItem("CS 3301-1", "CS 3301-1"),
                                  new ListItem("CS 3302-1", "CS 3302-1"),
                                  new ListItem("CS 3340-3", "CS 3340-3"),
                                  new ListItem("CS 4321-3", "CS 4321-3"),
                                  new ListItem("CS 4322-3", "CS 4322-3"),
                              };
        return templist;
    }

   

    protected void addClasses(object sender, EventArgs e)
    {
        int totalCost = 0;
        Label5.Text = "";
        for (int i = lbxAvailableClasses.Items.Count - 1; i >= 0; i--)
        {
            if (lbxAvailableClasses.Items[i].Selected && ((getTotalHours() + getTotalCredsAvailSelected()) <= 19))
            {
                lbxRegisteredClasses.Items.Add(lbxAvailableClasses.Items[i]);
                lbxAvailableClasses.Items.Remove(lbxAvailableClasses.Items[i]);
            }
            if (getTotalCredsAvailSelected() + getTotalHours() > 19)
            {
                Label4.Text = "";
                Label3.Text = "";
                Label5.Text = "You cannot register for more than 19 credit hours.";
            }
        }
        
        if (getTotalHours() <= 19)
        {
            totalCost = getTotalHours() * 100;
            Label4.Text = "$" + (totalCost + getFees()).ToString();
            Label3.Text = getTotalHours().ToString();
        }
    }



    protected void removeClasses(object sender, EventArgs e)
    {
        
        for (int i = lbxRegisteredClasses.Items.Count - 1; i >= 0; i--)  
        {
            if(lbxRegisteredClasses.Items[i].Selected){
            lbxAvailableClasses.Items.Add(lbxRegisteredClasses.Items[i]);
            lbxRegisteredClasses.Items.Remove(lbxRegisteredClasses.Items[i]);  
            }
            
        }
        int totalCost = getTotalHours() * 100;
        Label3.Text = getTotalHours().ToString();
        Label4.Text = "$" + (totalCost + getFees()).ToString();
        if (getTotalHours() <= 19)
        {
            Label5.Text = "";
        }
        if (getTotalHours() > 19)
        {
            Label5.Text = "You cannot register for more than 19 credit hours.";
        }
        
    }

    protected int getTotalHours()
    {
        int total = 0;
        foreach (ListItem li in lbxRegisteredClasses.Items)
        {
            String[] array = li.Value.Split('-');
            total += Int32.Parse(array[1]);
        }
        return total;
    }

   

    protected int getTotalCredsAvailSelected()
    {
        int total = 0;
        foreach (ListItem li in lbxAvailableClasses.Items)
        {
            if (li.Selected)
            {
                String[] array = li.Value.Split('-');
                total += Int32.Parse(array[1]);
            }
        }
        return total;
    }


    protected void resetData(object sender, EventArgs e)
    {
        Response.Redirect("default.aspx");
        //for (int i = lbxRegisteredClasses.Items.Count - 1; i >= 0; i--)
        //{
        //        lbxAvailableClasses.Items.Add(lbxRegisteredClasses.Items[i]);
        //        lbxRegisteredClasses.Items.Remove(lbxRegisteredClasses.Items[i]);
        //}
        //Label4.Text = "";
        //Label3.Text = "";
        //Label5.Text = "";
        //Label7.Text = "";
        //TextBox2.Text = "";
        //TextBox3.Text = "";
    }

    protected int getFees()
    {
        int total = 0;
        if (dormBox.Checked)
        {
            total += 1000;
        }
        if (mealBox.Checked)
        {
            total += 500;
        }
        if (footBox.Checked)
        {
            total += 50;
        }
        return total;
    }


    protected void makeAvailable(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        Boolean inhere = false, matchFound = false;
        Boolean creditsInRange;
        try
        {
            int credits  = Int32.Parse(TextBox3.Text);
            String courseName = TextBox2.Text;
            String courseAdd = "CS " + courseName + "-" + credits.ToString();
            creditsInRange = (credits < 11) && (credits > 0);
            foreach(ListItem li in lbxAvailableClasses.Items)
            {
                if (courseAdd == li.Text)
                {
                    matchFound = true;
                }
            }

            if (!matchFound && creditsInRange)
            {
                lbxAvailableClasses.Items.Add(new ListItem("CS " + courseName + "-" + credits.ToString(), "CS " + courseName + "-" + credits.ToString()));
                inhere = true;
            }
            if (!creditsInRange) 
            {
                Label7.Text = "Credits should be between 1 and 10 inclusive.";
                Label7.ForeColor = System.Drawing.Color.Red;
            }
            if (matchFound)
            {
                Label7.Text = "The class is already there.";
                Label7.ForeColor = System.Drawing.Color.Red;
            }  
        }
        catch (SystemException) { //tries to enter not a number for credit hours
            Label7.Text = "Enter a numerical value for credit hours.";
            Label7.ForeColor = System.Drawing.Color.Red;
        }
    }

    protected void removeClass(object sender, EventArgs e) 
    {
        Boolean inhere = false;
        try
        {
            int credits = Int32.Parse(TextBox3.Text);
            String courseName = TextBox2.Text;
            String remCourse = "CS " + courseName + "-" + credits.ToString();
            foreach (ListItem li in lbxAvailableClasses.Items)
            {
                if (remCourse == li.Text) //tries to remove class that is there
                {
                    lbxAvailableClasses.Items.Remove(li);
                    inhere = true;
                }
                if (!(remCourse == li.Text)) //tries to remove class that is not there
                {
                    Label7.Text = "Class not found.";
                    Label7.ForeColor = System.Drawing.Color.Red;
                }
            }
        }
        catch (SystemException) //tries to enter credit hours that is not a number
        {
            Label7.Text = "Enter a numerical value for credit hours.";
            Label7.ForeColor = System.Drawing.Color.Red;
        }
        if (inhere) { Label7.Text = ""; }
    }
}