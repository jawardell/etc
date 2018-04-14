<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Page2.aspx.cs" Inherits="Page2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:Button ID="readBtnData" runat="server" Text="Read Data" OnClick="readBtnData_Click" /><br><br>
         <asp:TextBox ID="txtMsg" runat="server" Height="175px" TextMode="MultiLine" Width="667px"></asp:TextBox>

    </div>
    </form>
</body>
</html>
