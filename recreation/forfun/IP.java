/*
 * Given a netmask, calculate all possible IP addresses 
 * and display them on screen. Also create a CSV file of the 
 * IP addresses.
 */
import java.util.*; 
import java.io.*; 

public class IP {
  public static void main(String[] args) {
    File file = new File("netmasks.csv");
    PrintWriter pw = null;
    try {
      pw = new PrintWriter(file);
    } catch(Exception e) {
      System.out.print("\nan exception was thrown\n");
      System.exit(1);
    }
    Scanner scanner = new Scanner(System.in);
    System.out.print("\n\n\tenter the netmask value 0-32\n");
    int netmask = scanner.nextInt();
    int host = 32 - netmask;
    //System.out.println("host=" + host);
    //System.out.println("netmask=" + netmask);
    //System.out.println("netmask+host=" + (netmask+host));
    String prefix = getNetworkPrefix(netmask);
    System.out.printf("\n\n\tthere are %d total ip addresses with a /%d netmask\n", (int)Math.pow(2,host), netmask);
    for(int i = 0; i < Math.pow(2, host); i++) {
      String node = getBinary(i, host);
      //System.out.print(getBinary(i) + "\n");
      System.out.print(getIpAddress(prefix, node) + "\n");
      pw.printf("%s,\n", getIpAddress(prefix, node));
    }

    pw.close();
    scanner.close();
  }

  public static String getBinary(int i, int host) {
    String s = (host != 0) ? "%" + host + "s" : "%1s";
    //System.out.println(s);
    String num = String.format(s, Integer.toBinaryString(i));
    String[] array = new String[num.length()];
    for(int j = 0; j < num.length(); j++) {
      if(num.charAt(j) == ' ') {
        array[j] = "0";
      } else {
        array[j] = Character.toString(num.charAt(j));
      }
    }
    String res = new String();
    for(int j = 0; j < array.length; j++) {
      res += array[j];
    }
    return res;
  }

  public static String getNetworkPrefix(int prefix) {
    //System.out.println("here is the prefix " + prefix);
    String res = new String();
    for(int i = 0; i < prefix; i++) {
      res += "1";
    }
    //System.out.println("here is the prefix " + res);
    return res;
  }

  public static String getIpAddress(String prefix, String host) {
    String res = new String();
    String sum = prefix + host;
    //System.out.println("prefix.length()=" + prefix.length());
    //System.out.println("host.length()=" + host.length());
    //System.out.println("here is the sum: " + sum + "\t" + sum.length());
    int pos = 0;
    for(int i = 0; i < sum.length() + 3; i++) {
      if(pos >= sum.length()) {
        break;
      }
      if((pos != 0) && (pos % 8 == 0)) {
        //System.out.println("this is pos and mod 8 is 0\t" + pos);
        res += ".";
      } else {
        //System.out.println("this is pos " + pos);
        //System.out.println("this is charat pos " + sum.charAt(pos));
        res += sum.charAt(pos);
      }
      pos++;
    }
    return res;
  }
}
