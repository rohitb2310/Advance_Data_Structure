import java.util.*;

class myexception extends Exception
{
	myexception(String msg)
	{
		super(msg);
	}
}

class Except
{
	String model;
	int s_size,price;

	void getdata()
	{
		Scanner sc=new Scanner(System.in);

		try
		{
			System.out.println("Enter model number:");
			model=sc.next();
			if(model.length()>4)
			{
				throw  new myexception("Model size is greater then expected");
 
			}
			System.out.println("Enter model screen  size:");
			s_size=sc.nextInt();
			if(s_size<12 || s_size>70)
			{
				throw new myexception("Screen size is greater than expected");

			}
			System.out.println("Enter model price:");
			price=sc.nextInt();
			if(price<5000 || price>70000)
			{
				throw new myexception("Price is is greater than expected");
				
			}
			System.out.println("Data Entered Sucessfully......!!!!!");

		}
		catch(myexception e)
		{
			System.out.println(e);
		}
	}
	public static void main(String args[])
	{
		Except F=new Except();
		F.getdata();
	}
}