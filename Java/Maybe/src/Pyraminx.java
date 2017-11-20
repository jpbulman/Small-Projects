public class Pyraminx {

    Tip T1;
    Tip T2;
    Tip T3;
    Tip T4;
    Center C1;
    Center C2;
    Center C3;
    Center C4;
    Edge E1;
    Edge E2;
    Edge E3;
    Edge E4;
    Edge E5;
    Edge E6;
    String Solution;

    Pyraminx(Tip T1,Tip T2,Tip T3,Tip T4,Center C1,Center C2,Center C3,Center C4,Edge E1,Edge E2,Edge E3,Edge E4,Edge E5,Edge E6,String Solution){
        this.T1=T1;
        this.T2=T2;
        this.T3=T3;
        this.T4=T4;
        this.C1=C1;
        this.C2=C2;
        this.C3=C3;
        this.C4=C4;
        this.E1=E1;
        this.E2=E2;
        this.E3=E3;
        this.E4=E4;
        this.E5=E5;
        this.E6=E6;
        this.Solution=Solution;
    }

    // Returns a new pyraminx instead of a mutated one
    Pyraminx Ro(){
        return new Pyraminx(T1,new Tip(T2.S3,T2.S1,T2.S2),T3,T4,C1,new Center(C2.S3,C2.S1,C2.S2),C3,C4,E1,new Edge(E5.S2,E5.S1),
                new Edge(E2.S2,E2.S1),E4,new Edge(E3.S1,E3.S2),E6,Solution+" R");
    }

    Pyraminx R(){
        //Order does matter here
        //Otherwise, the pieces can get mixed up with their changed parts and not their original pieces

        T2=new Tip(T2.S3,T2.S1,T2.S2);
        C2=new Center(C2.S3,C2.S1,C2.S2);
        E5=new Edge(E3.S1,E3.S2);
        E3=new Edge(E2.S2,E2.S1);
        E2=new Edge(E5.S2,E5.S1);
        Solution=Solution+" R";
        return this;
    }


} 