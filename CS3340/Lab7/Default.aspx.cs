using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack) {
            ArrayList rightItems = new ArrayList();
            rightItems.Add("Dontavious");
            rightItems.Add("Linda");
            rightItems.Add("Xavier");
            ListBox2.DataSource = rightItems;
            ListBox2.DataBind();

            ArrayList leftItems = new ArrayList();
            leftItems.Add("Wally");
            leftItems.Add("Suzy");
            leftItems.Add("Remmy");
            ListBox1.DataSource = leftItems;
            ListBox1.DataBind();
        }
    }



    protected void ListBox1_SelectedIndexChanged(object sender, EventArgs e)
    {
        System.Threading.Thread.Sleep(3000);
        String selected = ListBox1.SelectedItem.ToString();
        ListBox2.Items.Add(selected);
        ListBox1.Items.Remove(selected);
    }
    protected void ListBox2_SelectedIndexChanged(object sender, EventArgs e)
    {
        System.Threading.Thread.Sleep(3000);
        String selected = ListBox2.SelectedItem.ToString();
        ListBox1.Items.Add(selected);
        ListBox2.Items.Remove(selected);
    }

    protected void btnMoveFirst_Click(object sender, EventArgs e)
    {
        if (ListBox1.SelectedItem == null) {
            System.Threading.Thread.Sleep(3000);
            String selected1 = ListBox2.SelectedItem.ToString();
            ListBox1.Items.Add(selected1);
            ListBox2.Items.Remove(selected1);
        }

        if (ListBox2.SelectedItem == null) {
            System.Threading.Thread.Sleep(3000);
            String selected1 = ListBox1.SelectedItem.ToString();
            ListBox2.Items.Add(selected1);
            ListBox1.Items.Remove(selected1);
        }

    }
    protected void Timer1_Tick(object sender, EventArgs e)
    {
        lblTime.Text = DateTime.Now.ToLongTimeString();
    }
}