<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EmployeeSelection.aspx.cs" Inherits="EmployeeSelection" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>Employee Selection</h2>
        Return to <a href="http://lucius.valdosta.edu/jawardell/lab6/default.aspx">Lab 6</a>
        <br/><br/>
        <asp:DropDownList ID="ddlEmployees" runat="server" OnSelectedIndexChanged="ddEmployees_SelectedIndexChanged"></asp:DropDownList>
        <br/><br/>
        <asp:TextBox ID="txtMsg" runat="server" Height="191px" Width="430px" TextMode="MultiLine"></asp:TextBox>
    </div>
    </form>
</body>
</html>
