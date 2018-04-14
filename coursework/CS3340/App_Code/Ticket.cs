using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Summary description for Ticket
/// </summary>
public class Ticket 
{
    String name;
    int age;
    int seat;
    double price;

	public Ticket(String name, int age, int seat)
	{
        this.name = name;
        this.age = age;
        this.seat = seat;
        if (age <= 12) { this.price = 5; }
        else { this.price = 10; }
	}

    

    public Boolean equals(Object o) {
        if (o.GetType() == typeof(Ticket)) {
            Ticket ticket = (Ticket)o;
            return this.name == ticket.getName();
        }
        return false;
    }

    public double getPrice() {
        return price;
    }
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getSeat() {
        return seat;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setName(int seat) {
        this.seat = seat;
    }

    public String toString() {
        return "Name: " + name + " Age: " + age.ToString() + " Seat: " + seat.ToString() + " Price: $" + price.ToString() + ".00\n";
    }


}