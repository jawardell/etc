using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Collections;
using System.Web.UI.WebControls;

/// <summary>
/// Summary description for Event
/// </summary>
public class Event
{
    ArrayList tickets, availableSeats;
    String name;
    int seatStart, seatEnd;

	public Event(String name, int seatStart, int seatEnd)
	{
        tickets = new ArrayList();
        availableSeats = new ArrayList();
        this.name = name;
        this.seatStart = seatStart;
        this.seatEnd = seatEnd;
        int size = (seatEnd - (seatStart-1));
        for (int i = seatStart; i <= seatEnd; i++) {
            availableSeats.Add(i);
        }
	}

    public Boolean removeTicket(Ticket ticket) {
        if (tickets.Contains(ticket)) {
            availableSeats.Add(ticket.getSeat());
            tickets.Remove(ticket);
            return true;
        }

        return false;
    }

    public Ticket getTicket(String name) {
        Ticket ticket = null;
        foreach (Ticket ticket1 in tickets) {
            if (ticket1.getName().Equals(name)) {
                ticket = ticket1;
            }
            
        }
        return (Ticket)tickets[tickets.IndexOf(ticket)];
    }

    public Boolean addTicket(Ticket ticket) {
        Boolean sameName = false;
        foreach (Ticket ticket1 in tickets) {
            if (ticket.getName().Equals(ticket1.getName())) {
                sameName = true;
            }
        }

        /*foreach (int i in availableSeats) {
            if (i == ticket.getSeat()) {
                sameSeat = true;
            }
        }*/

        if(!sameName && !(availableSeats.Count == 0)) {
            tickets.Add(ticket);
            availableSeats.Remove(ticket.getSeat());
            return true;
        }
        return false;
    }

    public ArrayList getTickets() {
        return tickets;
    }
    public ArrayList getAvailableSeatsList()
    {
        return availableSeats;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSeatStart(int seatStart)
    {
        this.seatStart = seatStart;
    }

    public void setSeatEnd(int seatEnd)
    {
        this.seatEnd = seatEnd;
    }

    public String getName() {
        return name;
    }

    public int getSeatStart() {
        return seatStart;
    }

    public int getSeatEnd() {
        return seatEnd;
    }

    public double getTotalPrice()
    {
        double res = 0;
        foreach (Ticket ticket in tickets) {
            res += ticket.getPrice();
        }
        return res;
    }

    public double getAverage() {
        double res = 0;
        foreach (Ticket ticket in tickets) {
            res += ticket.getPrice();
        }
        return res / tickets.Count;
    }

    public Boolean hasTicket(Ticket ticket) {
        foreach (Ticket ticket1 in tickets) {
            if (ticket.getName() == ticket1.getName()) {
                return true;
            }
        }
        return false;
    }

    public Boolean seatTaken(Ticket ticket)
    {
        foreach (int seat in availableSeats) {
            if (seat == ticket.getSeat()) {
                return false;
            }
        }
        return true;
    }

    public String getAvailableSeats()
    {
        String res = "";
        foreach (int i in availableSeats) {
            res += i.ToString() + ", ";
        }
        if (res.Length > 2)
        {
            res = res.Substring(0, res.Length - 2);
            return res;
        }
        return res;
    }

    public String toString() {
        String res = "Event Name: " + name + "\nTickets Remaining: " + (availableSeats.Count) + "\tTickets purchased: " + tickets.Count.ToString() + "\n\nTickets: \n";
        foreach (Ticket ticket in tickets) {
            res += ticket.toString();
        }
        res += "\nTickets sold: " + tickets.Count.ToString() + "\nTickets Available:" + (((seatEnd - seatStart)+1) - tickets.Count) +
            "\nTicket Amount Total: $" + getTotalPrice().ToString() + ".00\nAvg Price Per Ticket: $" + getAverage().ToString() +
            "\nAvailable Seats: " + getAvailableSeats();
        return res;
    }
}