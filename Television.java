



import java.util.*;

public class Television 
{
	String model;
	int screen_size;
	int price;
	
	void readData()
	{
		Scanner In=new Scanner(System.in);
		try
		{
			System.out.println("Enter model No :");
			model=In.next();
			if(model.length()>4)
				throw new MyException("Exception in model No found!\n");

			System.out.println("Enter Screen size in Inches :");
			screen_size=In.nextInt();
			if(screen_size<12||screen_size>70)
				throw new MyException("Exception in size found!\n");

			System.out.println("Enter price in $ :");
			price=In.nextInt();
			if(price<0||price>5000)
				throw new MyException("Exception in price found!\n");

			System.out.println("Perfect Data !!!!!");

		}
		catch(MyException exce)
		{
			System.out.println(exce);
		}
	}

	public static void main(String[] args) 
	{
		Television test=new Television();	
		test.readData();
	}

} // end of class