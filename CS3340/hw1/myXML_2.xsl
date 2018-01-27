<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html style="font-family:Verdana;">
          <a href="https://lucius.valdosta.edu/jawardell/default.html">Home</a> > <a href="default.html">HW 1</a> > myXML.xml
            <body>
                <h2>Users</h2>
                <p>This is a table which organizes my XML information.</p>
                <table border="1">
                    <tr bgcolor="#ffffcc">
                        <th>Name</th>
                        <th>Role</th>
                        <th>ID</th>
                    </tr>
                    <xsl:for-each select="users/person">
                        <tr>
                            <td><xsl:value-of select="name"/></td>
                            <td><xsl:value-of select="role"/></td>
                            <td><xsl:value-of select="ID"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>