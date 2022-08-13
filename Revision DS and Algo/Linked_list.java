import java.util.Scanner;

class 	node{
	 int data;
	 node next;
	
	
	node( int data)
	{
		this.data=data;
		next=null;
	}
}

class LL{
    node head=null;
    public void insertFirst(int data)
    {
    	node nw=new node(data);
    	
    		nw.next=head;
        	head=nw;
        	return;
    }
    
    public void print()
    {
    	node temp=head;
    	while(temp!=null)
    	{
    		System.out.print(temp.data+"->");
    		temp=temp.next;
    	}
    	System.out.println("null");
    }
    
    
    public void insertatLast(int data)
    {
    	node nw=new node(data);
    	node temp=head;
    	while(temp.next!=null)
    	{
    		temp=temp.next;
    	}
    	temp.next=nw;
    }
    
    public void insertatIdx(int data,int idx)
    {
    	  if (head == null)
          {
              node nw = new node(data);
              nw.next = head;
              head = nw;
              return;
          }

          node temp = head;
          node nw = new node(data);
          int i = 0;
          while (i < idx - 1)
          {
              temp = temp.next;
              i++;
          }

          nw.next = temp.next;
          temp.next = nw;
    }
    
    public void deleteatFirst()
    {
    	head=head.next;
    	return;
    }
    
    public void deleteatLast()
    {
    	node temp = head;

        while (temp.next.next != null)
        {
            temp = temp.next;
        }
        temp.next = null;
    }
    
    public void deleteatIdx(int idx)
    {
    	node temp = head;

        int i = 0;
        while (i < idx - 1)
        {
            temp = temp.next;
            i++;
        }
        temp.next = temp.next.next;
    }
    
    
    
    
    
    
    
    
    
}

public class Linked_list {

	public static void main(String[] args) {
		LL l=new LL();
		int data;
		Scanner sc=new Scanner(System.in);
		int i=5;
		while(i > 0)
		{
			System.out.println("Enter the data in Linked list:- ");
			data=sc.nextInt();
			l.insertFirst(data);
			i--;
		}
		l.insertatLast(45);
		l.insertatIdx(100, 3);
//		l.deleteatFirst();
//		l.deleteatLast();
		l.deleteatIdx(3);
		l.print();
		
	}

}
