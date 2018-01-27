<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Lab 7 - Joanne Wardell</title>
    <style type="text/css">
        .auto-style1 {
            color: #CC3300;
        }
    </style>
</head>
<body>
    <h2>Lab7 - <a href="https://lucius.valdosta.edu/jawardell">Joanne Wardell</a></h2>

    <form id="form1" runat="server">
    <div>
    
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager> Ajax: Click a name in either list and it moves to the other list.<br>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <asp:Label ID="lblTime" runat="server" Text=""></asp:Label><br>
                <asp:ListBox ID="ListBox1" runat="server" AutoPostBack="True" ></asp:ListBox><!--OnSelectedIndexChanged="ListBox1_SelectedIndexChanged"-->
                <asp:ListBox ID="ListBox2" runat="server" AutoPostBack="True" ></asp:ListBox><!--OnSelectedIndexChanged="ListBox2_SelectedIndexChanged"-->
                <br />
                <asp:UpdateProgress ID="UpdateProgress1" runat="server">
                    <ProgressTemplate>
                        <span class="auto-style1">... moving name.</span>
                    </ProgressTemplate>
                </asp:UpdateProgress>
            </ContentTemplate>
            <Triggers>
                <asp:AsyncPostBackTrigger ControlID="btnMoveFirst" EventName="Click" />
            </Triggers>
        </asp:UpdatePanel>
        <asp:Button ID="btnMoveFirst" runat="server" Text="Move First" OnClick="btnMoveFirst_Click" />
        <br>
    
    </div>
    </form>
</body>
</html>
