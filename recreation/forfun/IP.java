/*
 * Given a netmask, calculate all possible IP addresses 
 * and display them on screen. Also create a CSV file of the 
 * IP addresses.
 */
import java.util.*; 
import java.io.*; 

public class IP {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int netmask = -1;
    if(args.length != 0) {
      netmask = Integer.parseInt(args[0]); 
    } else {
      System.out.print("\n\n\tenter the netmask value 0-32\n");
      netmask = scanner.nextInt();
    }
    if(netmask < 0) {
      System.out.println("netmask was never initialized. exiting now.");
      System.exit(1);
    }
    if(netmask > 32) {
      System.out.println("netmask must be in [0-32]");
      System.exit(1);
    }
    File file = new File("netmasks" + netmask + "_" + System.currentTimeMillis() + ".csv");
    PrintWriter pw = null;
    try {
      pw = new PrintWriter(file);
    } catch(Exception e) {
      System.out.print("\nan exception was thrown\n");
      System.exit(1);
    }
    int host = 32 - netmask;
    String prefix = getNetworkPrefix(netmask);
    System.out.printf("\n\n\tthere are %d total ip addresses with a /%d netmask\n", (int)Math.pow(2,host), netmask);
    for(int i = 0; i < Math.pow(2, host); i++) {
      String node = getBinary(i, host);
      System.out.print(getIpAddress(prefix, node) + "\n");
      pw.printf("%s,\n", getIpAddress(prefix, node));
    }

    pw.close();
    scanner.close();
  }

  public static String getBinary(int i, int host) {
    String s = (host != 0) ? "%" + host + "s" : "%1s";
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
    String res = new String();
    for(int i = 0; i < prefix; i++) {
      res += "1";
    }
    return res;
  }

  public static String getIpAddress(String prefix, String host) {
    String res = new String();
    String sum = prefix + host;
    int pos = 0;
    for(int i = 0; i < sum.length() + 3; i++) {
      if(pos >= sum.length()) {
        break;
      }
      if((pos != 0) && (pos % 8 == 0)) {
        res += ".";
      } else {
        res += sum.charAt(pos);
      }
      pos++;
    }
    return res;
  }
}
