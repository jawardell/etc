namespace hw4
{

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Web;

    /// <summary>
    /// Summary description for Property
    /// </summary>
    public class Property
    {
        private double price = 0;
        private double feet = 0;
        private double beds = 0;
        private double baths = 0;
        private double year = 0;
        private double cost = 0;

        public Property(double price, double feet, double beds, double baths, double year)
        {
            this.price = price;
            this.feet = feet;
            this.beds = beds;
            this.baths = baths;
            this.year = year;
            this.cost = price / feet;
        }


        public double Price { get { return price; } set { price = value; } }
        public double Feet { get { return feet; } set { feet = value; } }
        public double Beds { get { return beds; } set { beds = value; } }
        public double Baths { get { return baths; } set { baths = value; } }
        public double Year { get { return year; } set { year = value; } }
        public double Cost { get { return cost; } set { cost = value; } }

        public String toString()
        {
            return "$" +  price + "\t\t" + feet + "\t\t" + beds + "\t\t" + baths + "\t\t" + year + "\t\t$" + cost;
        }
    }
}