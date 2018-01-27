<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 8 - Joanne Wardell</title>
</head>
<body>
    <h2>Lab 8 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
    <a href="Page2.aspx">Page 2</a>&nbsp&nbsp
    <a href="Page3.aspx">Page 3</a>
    <form id="form1" runat="server">
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:jawardellConnectionString %>" SelectCommand="SELECT * FROM [Players]"></asp:SqlDataSource>

        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="PlayerID" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="PlayerID" HeaderText="PlayerID" InsertVisible="False" ReadOnly="True" SortExpression="PlayerID" />
                <asp:BoundField DataField="TeamID" HeaderText="TeamID" SortExpression="TeamID" />
                <asp:BoundField DataField="LName" HeaderText="LName" SortExpression="LName" />
                <asp:BoundField DataField="FName" HeaderText="FName" SortExpression="FName" />
                <asp:BoundField DataField="PNumber" HeaderText="PNumber" SortExpression="PNumber" />
                <asp:BoundField DataField="BDate" HeaderText="BDate" SortExpression="BDate" />
            </Columns>
        </asp:GridView>
        <br>
        <asp:TextBox ID="txtMsg" runat="server" Height="229px" TextMode="MultiLine" Width="660px"></asp:TextBox>
    <div>
    
    </div>
    </form>
</body>
</html>