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
      if(args[0].equals("pro")) {
        proMode();
      } 
      netmask = Integer.parseInt(args[0]); 
    } else  {
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
    System.out.printf("\n\n\ta /%d block can accommodate %d ip addresses\n", netmask, (int)Math.pow(2,host));
    for(int i = 0; i < Math.pow(2, host); i++) {
      String node = getBinary(i, host);
      String binIp = getIpAddress(prefix, node);
      System.out.print(binIp + " = " + getDecIp(binIp)+ "\n");
      //pw.printf("%s,\n", getIpAddress(prefix, node));
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
    for(int i = 1; i <= 35 + 3; i++) {
      if(pos == sum.length()) {
        break;
      }
      if((i != 32) && (i % 9 == 0)) {
        res += ".";
      } else {
        res += sum.charAt(pos);
        pos++;
      }
    }
    return res;
  }

  public static String getDecIp(String binIp) {
    String[] bytes = binIp.split("\\.");
    String res = new String();
    int i = 1;
    for(String s: bytes) {
      res += Integer.parseInt(s, 2);
      if(i != 4) {
        res += ".";
      }
      i++;
    }
    return res;
  }


  public static String getBinIp(String decIp) {
    System.out.println("here's the dec ip - " + decIp);
    String[] decs = decIp.split("\\.");
    String res = new String();
    int i = 1;
    for(String s : decs) {
      for(int j = 0; j < (8 - Integer.toBinaryString(Integer.parseInt(s)).length()); j++) {
        res += "0";
      }
      res += Integer.toBinaryString(Integer.parseInt(s));
      if(i != 4) {
        res += ".";
      }
      i++;
    }
    return res;
  }

  public static void proMode() {
    System.out.print("\n\t\tPRO!!!!!!!\n\n");
    Scanner input = new Scanner(System.in);
    System.out.println("enter the netmask");
    int netmask  = input.nextInt();
    int host = 32 - netmask;
    String prefix = getNetworkPrefix(netmask);
    System.out.println("here's the prefix- "+ prefix);
    String binIp = getIpAddress(prefix, getBinary(0, host));
    System.out.println("here's the ip address- " + binIp);
    String startIp = initIp(binIp.split("\\."));
    String endIp = getBroadcast(startIp);
    System.out.println("endIp= " + endIp);
    System.out.println("here's the start IP- " + startIp + " = " + getBinIp(startIp));
    System.out.println("here's the end IP- " + endIp + " = " + getBinIp(endIp));
    System.exit(0);
  }

  public static String initIp(String[] ipArray) {
    Scanner input = new Scanner(System.in);
    String res = new String();
    int i = 1;
    for(String s : ipArray) {
      int low = 0;
      int high = Integer.parseInt(s, 2);
      System.out.printf("Choose octect %d. Can range from %d to %d.\n", i, low, high);
      res += input.next();
      if(i != 4) {
        res += ".";
      }
      i++;
    }
    return res;
  }


  public static String getBroadcast(String startIp) {
    String[] array = startIp.split("\\.");
    array[3] = "255";
    String res = new String();
    int i = 1;
    for(String s : array) {
      res += s;
      if(i != 4) {
        res += ".";
      }
      i++;
    }
    return res;
  }


}
