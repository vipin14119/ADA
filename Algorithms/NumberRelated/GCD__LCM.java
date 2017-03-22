import java.util.*;
public class iter{
  public static void main(String[] ra){
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the numbers-To end enter -1");
    ArrayList<Integer> arr = new ArrayList<Integer>();
    Iterator<Integer> itr = arr.iterator();
    Integer n=0;
    while(n!=-1){
      n = s.nextInt();
      if(n!=-1)
        arr.add(n);
    }
    Integer largest=-1;
    for(Integer i:arr)
      if(i>largest)
        largest=i;
    Integer back=largest;
    boolean found=false;
    while(!found){
      Integer d=0;
      for(Integer i:arr)
        if(largest%i!=0)
          d=1;
      if(d==0)
        found=true;
      else
        largest+=back;
    }
    System.out.println("The LCM of the given numbers is "+largest);
    System.out.println("Enter the numbers - To end press -1");
    ArrayList<Integer> a = new ArrayList<Integer>();
    Iterator<Integer> it = a.iterator();
    int an=0;
    while(an!=-1){
      an=s.nextInt();
      if(an!=-1)
        a.add(an);
    }
    int lower=99999;
    for(int i:a)
      if(i<lower)
        lower=i;
    lower/=2;
    int st=2;
    found=false;
    while(!found&&st<=lower){
      int d=0;
      for(int i:a)
        if(i%st!=0){
          d=1;
          break;
        }
      if(d==1)
        st+=1;
      else
        found=true;
    }
    if(!found)  st=1;
    System.out.println("The GCD of the given numbers is "+st);
  }
}
