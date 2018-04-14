<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 6 - Joanne Wardell</title>
</head>
<body style="font-family: Verdana;">

    <form id="form1" runat="server">
    <h2>Lab 6 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
        

    <div>
        <asp:LinkButton ID="LinkButton1" runat="server" PostBackUrl="EmployeeSelection.aspx">Employee Selection</asp:LinkButton><br>
        Balance<asp:TextBox ID="txtBalance" runat="server"></asp:TextBox>
        <asp:Button ID="btnAdd" runat="server" OnClick="btnAddAccount_Click" Text="Add Account" />     
        <asp:Button ID="btnClearAccounts" runat="server" Text="Clear Accounts from Memory" OnClick="btnClearAccounts_Click" Width="199px" />
        <asp:Button ID="btnSummary" runat="server" Text="Summary" OnClick="btnSummary_Click" />
        <br>
        Num Accounts:  
        <asp:Label ID="lblNumAccounts" runat="server" Text=""></asp:Label>
        <br>
        <asp:TextBox ID="txtMsg" runat="server" Height="157px" TextMode="MultiLine" Width="398px"></asp:TextBox>
    
    </div>
    </form>
</body>
</html>
