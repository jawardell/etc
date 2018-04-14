<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Summary.aspx.cs" Inherits="Summary" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 6 - Summary</title>
</head>
<body>
    <h2>Account Summary</h2>
    <form id="form1" runat="server">
    <div>
    
        <asp:Button ID="btnAddAccount" runat="server" Text="Add Account" OnClick="btnAddAccount_Click" />
        <asp:Button ID="btnStartOver" runat="server" Text="Start Over" OnClick="btnStartOver_Click" />
        <br>
        <asp:TextBox ID="txtSummary" runat="server" Height="234px" Width="550px" TextMode="MultiLine"></asp:TextBox>
        

    </div>
    </form>
</body>
</html>
