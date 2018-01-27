<%@ Page Language="C#" AutoEventWireup="true" CodeFile="eventSummary.aspx.cs" Inherits="eventSummary" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
    <script>
        function goBack() {
            window.history.back();
        }
    </script>
<head runat="server">
    <title>Event Summary</title>
</head>
<body>


    
    <form id="form1" runat="server">
    <h2>Ticket Holders for
        <i><asp:Label ID="Label1" runat="server" Text=""></asp:Label></i>
        </h2>


    
    <div>
    
        
        <button onclick="goBack()">Sell More Tickets</button>&nbsp
        Sort:&nbsp
        <asp:RadioButton ID="RadioButton2" runat="server" />Order Purchased
        <asp:RadioButton ID="RadioButton3" runat="server" />Name
        <asp:RadioButton ID="RadioButton4" runat="server" />Seat&nbsp
        <asp:Button ID="Button3" runat="server" Text="Sort!" />
        <br><br>
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click1" Text="debug" />
        <br />Remove Ticket Holder&nbsp
        <asp:DropDownList ID="DropDownList1" runat="server" />&nbsp
        <asp:Button ID="Button2" runat="server" Text="Remove" OnClick="Button2_Click" />
        <br />
        <asp:TextBox ID="TextBox1" runat="server" Height="157px" Width="713px" TextMode="MultiLine"></asp:TextBox>
        
        
    
    </div>
    </form>
</body>
</html>
