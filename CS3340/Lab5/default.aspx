<%@ Page Language="C#" AutoEventWireup="true" CodeFile="default.aspx.cs" Inherits="_default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 5 Joanne Wardell</title>
</head>
<body>
    <form id="form1" runat="server">
    <h2>
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
        Lab 5 <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
    <div>
    
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <asp:Button ID="btnCompute" runat="server" Text="Square Root" onClick="btnCompute_Click"/>
                <asp:TextBox ID="txtInput" runat="server"></asp:TextBox>
                <asp:Label ID="lblAnswer" runat="server" Text=""></asp:Label>
            </ContentTemplate>
        </asp:UpdatePanel>
    
    </div>
    </form>
</body>
</html>
