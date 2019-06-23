import java.util.*;
class ass11_main
{
	public static void main(String args[])
	{
		String name;

		Scanner sc =new Scanner(System.in);
		System.out.println("What is  your name:");
		name=sc.next();

		ass11_1 A=new ass11_1();

		A.print_hello(name);

		A.displaylocal();

		A.displayglobal();

		System.out.println("What is todays day::");
		A.day=sc.next();
		System.out.println("Today is:" +A.day);

	}

}