<%@ Page Language="C#" AutoEventWireup="true" CodeFile="default.aspx.cs" Inherits="_default" %>
<style type="text/css">
    .auto-style1 {
        width: 240px;
    }
    .auto-style2 {
        width: 181px;
    }
    .auto-style3 {
        width: 240px;
        height: 36px;
    }
    .auto-style4 {
        width: 181px;
        height: 36px;
    }
    .auto-style5 {
        height: 36px;
    }
    .auto-style6 {
        height: 41px;
    }
</style>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml" style="font-family: Verdana;">
<head runat="server">
    <title>HW2 - Joanne Wardell</title>
    <a href="https://lucius.valdosta.edu/jawardell">Home</a> > HW2
</head>
<body style="height: 179px">
    
    <form id="form1" runat="server">
    <h2>Course Registration System</h2>
        <table>
            <tr>
                <td colspan="3" class="auto-style6">

                    <asp:CheckBox ID="dormBox" runat="server" />Dorm     

                    <asp:CheckBox ID="mealBox" runat="server" />Meal Plan     

                    <asp:CheckBox ID="footBox" runat="server" />Football Tix

                </td>
            </tr>
            <tr>
                <td class="auto-style3">Available Classes</td>
                <td class="auto-style4">
                    
                </td>
                <td class="auto-style5">Registered Classes</td>
            </tr>
            <tr>
                <td class="auto-style1">
                    
                    <asp:ListBox ID="lbxAvailableClasses" runat="server" Height="216px" Width="231px" SelectionMode="Multiple"></asp:ListBox>
                </td>
                <td class="auto-style2">
                    
                    
                    <asp:Button ID="Button1" runat="server" Text="Add" OnClick="addClasses" />
                    <br>
                    <asp:Button ID="Button2" runat="server" Text="Remove" OnClick="removeClasses"  />
                    <br>
                    <asp:Button ID="Button3" runat="server" Text="Reset" OnClick="resetData" />
                    <br><br>
                    
                    
                   
                    <asp:Label ID="Label1" runat="server" Text="Total Hours:"></asp:Label>
                    <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
                    <br>
                    
                    
                   
                    <asp:Label ID="Label2" runat="server" Text="Total Cost:"></asp:Label>
                    <asp:Label ID="Label4" runat="server" Text=""></asp:Label>
                    
                    
                   
                </td>
                <td>
                    <asp:ListBox ID="lbxRegisteredClasses" runat="server" Height="216px" Width="221px" SelectionMode="Multiple"></asp:ListBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1" colspan ="3">
                    <asp:Label ID="Label5" runat="server" Text=""></asp:Label>

                </td>
            </tr>
            <tr>
                <td colspan="3">
                    Class Number: <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                    Credits:
                    <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                    <asp:Label ID="Label7" runat="server" Text=""></asp:Label>
                </td>
            </tr>
            <tr>
                <td colspan="3">

                    <asp:Button ID="Button4" runat="server" Text="Make Available" OnClick="makeAvailable"/>
                    &ensp;
                    <asp:Button ID="Button5" runat="server" Text="Remove From Available" OnClick="removeClass"/>

                </td>
            </tr>
            <tr>
                <td colspan="3">
                    
                    <asp:Label ID="Label6" runat="server" Text=""></asp:Label>
                    
                </td>
            </tr>
            <!--<tr>
                <td colspan="3">
                    
                    <asp:TextBox ID="TextBox1" runat="server" Height="158px" Width="647px"></asp:TextBox>
                    
                </td>
            </tr>-->
        </table>    
    
    
    </form>
</body>
</html>
