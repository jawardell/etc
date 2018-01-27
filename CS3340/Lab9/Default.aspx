<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 9 - Joanne Wardell</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <h2>Lab 9 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a> and <a href="https://lucius.valdosta.edu/keburnett/Homepage/CourseHome.html">Keirsten Burnett</a></h2>
        <br>
        <asp:RadioButtonList ID="rblDataBase" runat="server" AutoPostBack="True" RepeatDirection="Horizontal">
            <asp:ListItem>Access</asp:ListItem>
            <asp:ListItem>SQL Server</asp:ListItem>
        </asp:RadioButtonList>
        <asp:GridView ID="gvPlayers" runat="server" AutoGenerateColumns="False" DataKeyNames="PlayerID" DataSourceID="dsSqlServerPlayers" AllowPaging="True" AllowSorting="True" BackColor="White" BorderColor="#DEDFDE" BorderStyle="None" BorderWidth="1px" CellPadding="4" Font-Names="Georgia" ForeColor="Black" GridLines="Vertical">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:CommandField ShowSelectButton="True" />
                <asp:BoundField DataField="PlayerID" HeaderText="PlayerID" InsertVisible="False" ReadOnly="True" SortExpression="PlayerID" />
                <asp:BoundField DataField="LName" HeaderText="LName" SortExpression="LName" />
                <asp:BoundField DataField="FName" HeaderText="FName" SortExpression="FName" />
                <asp:BoundField DataField="PNumber" HeaderText="PNumber" SortExpression="PNumber" />
                <asp:BoundField DataField="BDate" HeaderText="BDate" SortExpression="BDate" />
            </Columns>
            <FooterStyle BackColor="#CCCC99" />
            <HeaderStyle BackColor="#6B696B" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#F7F7DE" ForeColor="Black" HorizontalAlign="Right" />
            <RowStyle BackColor="#F7F7DE" />
            <SelectedRowStyle BackColor="#CE5D5A" Font-Bold="True" ForeColor="White" />
            <SortedAscendingCellStyle BackColor="#FBFBF2" />
            <SortedAscendingHeaderStyle BackColor="#848384" />
            <SortedDescendingCellStyle BackColor="#EAEAD3" />
            <SortedDescendingHeaderStyle BackColor="#575357" />
        </asp:GridView>
        <asp:SqlDataSource ID="dsAccessPlayers" runat="server" ConnectionString="<%$ ConnectionStrings:playersConnectionString %>" ProviderName="<%$ ConnectionStrings:playersConnectionString.ProviderName %>" SelectCommand="SELECT [PlayerID], [LName], [FName], [PNumber], [BDate] FROM [Players]"></asp:SqlDataSource>
        <asp:SqlDataSource ID="dsSqlServerPlayers" runat="server" ConnectionString="<%$ ConnectionStrings:jawardellConnectionString1 %>" SelectCommand="SELECT [PlayerID], [LName], [FName], [PNumber], [BDate] FROM [Players]"></asp:SqlDataSource>
        <br>
        <asp:TextBox ID="txtMsg" runat="server"></asp:TextBox>
        <br>
    </div>
    </form>
</body>
</html>
