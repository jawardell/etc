using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class EmployeeSelection : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            txtMsg.Text += "First time on page" + Environment.NewLine;
            List<Employee> employees = new List<Employee>();
            StreamReader reader = new StreamReader(Server.MapPath("employees.txt"));
            while (!reader.EndOfStream)
            {
                String empString = reader.ReadLine();
                String[] empData = empString.Split();
                Employee emp = new Employee(Convert.ToInt32(empData[0]), empData[1],
                empData[2]);
                employees.Add(emp);
            }
            ddlEmployees.DataSource = employees;
            ddlEmployees.DataTextField = "LastName";
            ddlEmployees.DataValueField = "ID";
            ddlEmployees.DataBind();
            reader.Close();
        }
        else
        {
            txtMsg.Text += "Postback" + Environment.NewLine;
        }
    }

    protected void ddEmployees_SelectedIndexChanged(object sender, EventArgs e)
    {
        ListItem li = ddlEmployees.SelectedItem;
        String name = li.Text;
        String id = li.Value;
        txtMsg.Text += "You selected: " + name + " " + id + Environment.NewLine;

    }
}