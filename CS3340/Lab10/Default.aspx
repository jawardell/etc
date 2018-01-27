<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 10 - Joanne Wardell</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>Lab 10 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
    </div>
        <asp:RadioButtonList ID="rblDataBase" runat="server" AutoPostBack="True" OnSelectedIndexChanged="rblDataBase_SelectedIndexChanged" RepeatDirection="Horizontal">
            <asp:ListItem Value="Access"></asp:ListItem>
            <asp:ListItem Selected="True">SQL Server</asp:ListItem>
        </asp:RadioButtonList>
        <asp:GridView ID="gvPlayers" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" DataKeyNames="PlayerID" DataSourceID="dsSqlServerPlayers" OnSelectedIndexChanged="gvPlayers_SelectedIndexChanged" BackColor="White" BorderColor="#336666" BorderStyle="Double" BorderWidth="3px" CellPadding="4" Font-Names="Georgia" GridLines="Horizontal">
            <Columns>
                <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
                <asp:BoundField DataField="PlayerID" HeaderText="PlayerID" InsertVisible="False" ReadOnly="True" SortExpression="PlayerID" />
                <asp:BoundField DataField="LName" HeaderText="LName" SortExpression="LName" />
                <asp:BoundField DataField="PNumber" HeaderText="PNumber" SortExpression="PNumber" />
                <asp:BoundField DataField="FName" HeaderText="FName" SortExpression="FName" />
                <asp:BoundField DataField="BDate" HeaderText="BDate" SortExpression="BDate" />
            </Columns>
            <EmptyDataRowStyle BackColor="#CC6699" BorderColor="#660033" />
            <FooterStyle BackColor="White" ForeColor="#333333" />
            <HeaderStyle BackColor="#336666" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#336666" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="White" ForeColor="#333333" />
            <SelectedRowStyle BackColor="#339966" Font-Bold="True" ForeColor="White" />
            <SortedAscendingCellStyle BackColor="#F7F7F7" />
            <SortedAscendingHeaderStyle BackColor="#487575" />
            <SortedDescendingCellStyle BackColor="#E5E5E5" />
            <SortedDescendingHeaderStyle BackColor="#275353" />
        </asp:GridView>
        <asp:SqlDataSource ID="dsAccessPlayers" runat="server" ConnectionString="<%$ ConnectionStrings:accessConnectionString %>" DeleteCommand="DELETE FROM [Players] WHERE [PlayerID] = ?" InsertCommand="INSERT INTO [Players] ([PlayerID], [LName], [PNumber], [FName], [BDate]) VALUES (?, ?, ?, ?, ?)" ProviderName="<%$ ConnectionStrings:accessConnectionString.ProviderName %>" SelectCommand="SELECT [PlayerID], [LName], [PNumber], [FName], [BDate] FROM [Players]" UpdateCommand="UPDATE [Players] SET [LName] = ?, [PNumber] = ?, [FName] = ?, [BDate] = ? WHERE [PlayerID] = ?">
            <DeleteParameters>
                <asp:Parameter Name="PlayerID" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="PlayerID" Type="Int32" />
                <asp:Parameter Name="LName" Type="String" />
                <asp:Parameter Name="PNumber" Type="Int32" />
                <asp:Parameter Name="FName" Type="String" />
                <asp:Parameter Name="BDate" Type="DateTime" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="LName" Type="String" />
                <asp:Parameter Name="PNumber" Type="Int32" />
                <asp:Parameter Name="FName" Type="String" />
                <asp:Parameter Name="BDate" Type="DateTime" />
                <asp:Parameter Name="PlayerID" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <asp:SqlDataSource ID="dsSqlServerPlayers" runat="server" ConnectionString="<%$ ConnectionStrings:jawardellConnectionString %>" DeleteCommand="DELETE FROM [Players] WHERE [PlayerID] = @PlayerID" InsertCommand="INSERT INTO [Players] ([LName], [PNumber], [FName], [BDate]) VALUES (@LName, @PNumber, @FName, @BDate)" SelectCommand="SELECT [PlayerID], [LName], [PNumber], [FName], [BDate] FROM [Players]" UpdateCommand="UPDATE [Players] SET [LName] = @LName, [PNumber] = @PNumber, [FName] = @FName, [BDate] = @BDate WHERE [PlayerID] = @PlayerID">
            <DeleteParameters>
                <asp:Parameter Name="PlayerID" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="LName" Type="String" />
                <asp:Parameter Name="PNumber" Type="Int32" />
                <asp:Parameter Name="FName" Type="String" />
                <asp:Parameter Name="BDate" Type="DateTime" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="LName" Type="String" />
                <asp:Parameter Name="PNumber" Type="Int32" />
                <asp:Parameter Name="FName" Type="String" />
                <asp:Parameter Name="BDate" Type="DateTime" />
                <asp:Parameter Name="PlayerID" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource><br>
        <asp:TextBox ID="txtMsg" runat="server" Height="145px" TextMode="MultiLine" Width="633px"></asp:TextBox>
    </form>
</body>
</html>
