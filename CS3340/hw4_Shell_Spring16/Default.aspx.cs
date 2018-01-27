using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Data.SqlClient;
using hw4;

public partial class _Default : System.Web.UI.Page
{
    // Set database type. If working on campus use:
    string dbType = "SQL_Server";
    // Open App_Code/hw4/ConnectionFactory.cs and examine the GetCommand method.
    // Open Web.config and examine the connectionStrings node.



    List<Property> props = null;
    // If working from home, use:
    //String dbType = "Access_Patients";

    protected void Page_Load(object sender, EventArgs e)
    {
        props = getPropertyList(dbType);
        displayPropertStats(props);
        displayProperties(props);
    }

    private List<Property> getPropertyList(string dbType)
    {
        List<Property> props = new List<Property>();
        
        try
        {
            //IDbConnection connection = new SqlConnection();
            //connection.ConnectionString = "Data Source=narcissa;Initial Catalog=jawardell;Integrated Security=True";
            IDbCommand command = ConnectionFactory.GetCommand(dbType);
            command.CommandText = getSQL();
            command.Connection.Open();
            IDataReader datareader = command.ExecuteReader();
            while (datareader.Read())
            {
                double price = datareader.GetDouble(3);
                double feet = datareader.GetDouble(5);
                double beds = datareader.GetDouble(6);
                double baths = datareader.GetDouble(7);
                double year = datareader.GetDouble(17);
                Property prop = new Property(price, feet, beds, baths, year);
                props.Add(prop);
            }

            datareader.Close();
            command.Connection.Close();

        }
        catch (Exception ex)
        {
            txtMsg.Text = "\r\nError reading data\r\n";
            txtMsg.Text += ex.ToString();
        }
        return props;
        
    }




    private string getSQL()
    {
        return "SELECT * FROM Properties";
    }

    private void displayPropertStats(List<Property> props)
    {
        double avg = 0;
        int aboveavg = 0 ;
        foreach (Property prop in props) {
            avg += prop.Price;
        }
        avg = (avg / props.Count);
        foreach (Property prop in props) {
            if (prop.Price > avg) {
                aboveavg += 1;
            }
        }

        lblNumProperties.Text = props.Count.ToString();
        lblAveragePrice.Text = "$" + avg.ToString();
        lblNumAboveAvgPrice.Text =  aboveavg.ToString();
    }

    private void displayProperties(List<Property> props)
    {
        String msg = "";
        foreach (Property prop in props) {
            msg += prop.toString() + "\n";
        }

        txtProperties.Text = msg;
    }
    protected void rblSortType_SelectedIndexChanged(object sender, EventArgs e)
    {
        //txtProperties.Text = "";
        //Property[] propArr = new Property[props.Count];
        //List<Property> propscopy = new List<Property>();
        //foreach (Property prop in props) {
        //    propscopy.Add(prop);
        //}
        //while (propscopy.Count != 0) {
        //    foreach (Property prop in props) {

                
        //    }
        //}
        // Implement this if you can. It will require some changes to the code above and
        // some refactoring.
    }
}