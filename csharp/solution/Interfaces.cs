using System;

namespace Interfaces
{
	//
	// interface IPromotable
	//   promotion to a new job at work
	//
	interface IPromotable
	{
		void Promote();
	}

	//
	// class Employee
	//   Represents an employee of a corporation.
	//   Note that the class contains no abstract methods but should still be made
	//   abstract becauase the idea of "Employee" is an abstract concept.
	//
	abstract class Employee
	{
		//
		// fields (public for simplicity...real code should use properties)
		//
		public string Name;
		public double Salary;

		//
		// protected constructor to limit access to derived classes
		//
		protected Employee(string name, double salary)
		{
			Name   = name;
			Salary = salary;
		}

		//
		// Print method
		//   virtual so will be dynamically bound
		//
		public virtual void Print()
		{
			Console.WriteLine("Name  : {0}", Name);
			Console.WriteLine("Salary: {0}", Salary);
		}
	}

	//
	// class Programmer
	//   represents a computer programmer at a corporation
	//   programmers are eligible for promotion within the company
	//
	class Programmer : Employee, IPromotable
	{
		double averageOT;

		public Programmer(string name, double salary, double averageOT)
			: base(name, salary)
		{
			this.averageOT = averageOT;
		}

		//
		// Implement the Promote method from the IPromotable interface
		//
		public void Promote()
		{
			Salary *= 1.1;
		}

		public override void Print()
		{
			Console.WriteLine("Programmer");
			base.Print();
			Console.WriteLine("Average OT: {0}", averageOT);
		}
	}

	//
	// class Manager
	//   represents a manager at a corporation
	//   managers are eligible for promotion within the company
	//
	class Manager : Employee, IPromotable
	{
		string assistant;

		public Manager(string name, double salary, string assistant)
			: base(name, salary)
		{
			this.assistant = assistant;
		}

		//
		// Implement the Promote method from the IPromotable interface
		//
		public void Promote()
		{
			Salary *= 1.5;
		}

		public override void Print()
		{
			Console.WriteLine("Manager");
			base.Print();
			Console.WriteLine("Assistant: {0}", assistant);
		}
	}

	//
	// class Intern
	//   represents an intern at a corporation
	//   interns are temporary employees so they are not eligible for promotion
	//
	class Intern : Employee
	{
		int lengthOfInternship;

		public Intern(string name, double salary, int lengthOfInternship)
			: base(name, salary)
		{
			this.lengthOfInternship = lengthOfInternship;
		}

		public override void Print()
		{
			Console.WriteLine("Intern");
			base.Print();
			Console.WriteLine("Length of internship(months): {0}", lengthOfInternship);
		}
	}

	class Program
	{
		static void Main()
		{
			//
			// array of Employee references
			//
			Employee[] emps = new Employee[3];

			//
			// fill array with various types of employees
			//
			emps[0] = new Programmer("Sally", 45000, 4.6);
			emps[1] = new Manager("Ann", 120000, "George");
			emps[2] = new Intern("Bob", 4000, 3);

			foreach (Employee e in emps)
			{
				e.Print();
				Console.WriteLine();
			}

			//
			// step through the array of employees
			//
			foreach (Employee e in emps)
			{
				//
				// test if the employee is eligible for promotion
				// notice we can use operator is to test for implementation of an interface
				//
				if (e is IPromotable)
				{
					//
					// we want to call the IPromotable Promote method
					// this method is not in the Employee class so it
					// cannot be called through the Employee reference
					// we have in the array
					//
					// cast to obtain an IPromotable reference
					// we could also cast to either Programmer or Manager but that would
					// not be as general: we would have to test which case we were in and
					// then add new cases as new types of promoteable employees were created
					//
					IPromotable p = (IPromotable)e;

					//
					// can call Promote through IPromotable reference
					//
					p.Promote();
				}
			}

			foreach (Employee e in emps)
			{
				e.Print();
				Console.WriteLine();
			}

		}
	}
}