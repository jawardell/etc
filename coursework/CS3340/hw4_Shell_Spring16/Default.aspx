﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link href="site.css" rel="stylesheet" type="text/css" />
    <style type="text/css">
        .auto-style1 {
            border-style: solid;
            border-width: 1px;
        }
        .auto-style2 {
            font-size: small;
        }
    </style>
</head>
<body>
    <h2>HW 4 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>
    <p><a href="Patients.aspx">Patients</a></p>
    <form id="form1" runat="server">
    <div>
    
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <p>
                    <table class="auto-style1">
                        <tr>
                            <td>Num Properties: </td>
                            <td>
                                <asp:Label ID="lblNumProperties" runat="server" ForeColor="Red" Text="Label"></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>Avg Price:</td>
                            <td>
                                <asp:Label ID="lblAveragePrice" runat="server" ForeColor="Red" Text="Label"></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>Num Above Avg: </td>
                            <td>
                                <asp:Label ID="lblNumAboveAvgPrice" runat="server" ForeColor="Red" Text="Label"></asp:Label>
                            </td>
                        </tr>
                    </table>
                </p>
                <p>
                    Sort:<asp:RadioButtonList ID="rblSortType" runat="server" AutoPostBack="True" onSelectedindexchanged="rblSortType_SelectedIndexChanged" RepeatDirection="Horizontal" RepeatLayout="Flow">
                        <asp:ListItem Selected="True">Price</asp:ListItem>
                        <asp:ListItem>Sq. Feet</asp:ListItem>
                    </asp:RadioButtonList>
                </p>
                <p>
                    All Properties<br /> <span class="auto-style2">
                        Price&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         Sq.Feet&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
                        Beds&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
                        Baths&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
                        Year Built&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
                        $/Sq.Foot</span><br class="auto-style2" />
                    <asp:TextBox ID="txtProperties" runat="server" Height="232px" TextMode="MultiLine" Width="1036px"></asp:TextBox>
                    <br />
                    <br />
                    Debug Info<br />
                    </p>
            
                <p>
                    <asp:TextBox ID="txtMsg" runat="server" Height="232px" TextMode="MultiLine" Width="503px"></asp:TextBox>
                </p>
            
            </ContentTemplate>
        </asp:UpdatePanel>
    
    </div>
    </form>
</body>
</html>
