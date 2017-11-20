public class Tip extends AbstractPiece {

    Sticker S1;
    Sticker S2;
    Sticker S3;

    Tip(Sticker S1,Sticker S2,Sticker S3){
        super(3); //Tips always have 3 stickers
        this.S1=S1;
        this.S2=S2;
        this.S3=S3;
    }

} 