<%@ Page Language="C#" AutoEventWireup="true" CodeFile="default.aspx.cs" Inherits="_default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Joanne Wardell - HW3</title>
    <h2>HW 3 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
</head>
<body>
    <form id="form1" runat="server">
    <div style="border: thin groove black;   padding:2%;">
       
        Event Name:
        <asp:TextBox ID="TextBox1" runat="server" Width="150px"></asp:TextBox>&nbsp&nbsp&nbsp
        
        Available Seat Numbers:&nbsp

        First:
        <asp:TextBox ID="TextBox2" runat="server" Width="50px"></asp:TextBox>&nbsp

        Last:
        <asp:TextBox ID="TextBox3" runat="server" Width="50px"></asp:TextBox>&nbsp

        <asp:Button ID="Button1" runat="server" Text="Make Event" OnClick="Button1_Click" />

    </div>
        <asp:Panel runat="server" ID="ticketArena">
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
            &nbsp;tickets available<br>
        Name:
        <asp:TextBox ID="TextBox4" runat="server" Width="150px"></asp:TextBox>&nbsp&nbsp&nbsp
        
        Age:&nbsp
        <asp:TextBox ID="TextBox5" runat="server" Width="50px"></asp:TextBox>&nbsp
        
        Seat:&nbsp
        <asp:DropDownList ID="DropDownList1" runat="server"></asp:DropDownList>&nbsp
        

        

        <asp:Button ID="Button2" runat="server" Text="Purchase" OnClick="Button2_Click" />&nbsp

        <asp:Button ID="Button3" runat="server" Text="Event Summary" OnClick="Button3_Click" />

            
        </asp:Panel>
        <asp:Label ID="Label2" runat="server" Text=""></asp:Label>
        <br>
    <asp:TextBox ID="TextBox6" runat="server" Height="221px" Width="784px" TextMode="MultiLine"></asp:TextBox>
    </form>
</body>
</html>