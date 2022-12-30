import java.io.*;
import java.nio.Buffer;

public class lab0 {
    public static void main(String[]args) throws FileNotFoundException {
        char[] dict = new char[41];
        StringBuilder answer = new StringBuilder("");
        //读取dict文件内容
        try{
            File dictFile = new File("./dict.txt");
            BufferedReader br = new BufferedReader(new FileReader(dictFile));
            String str;
            int a = 0;
            while((str = br.readLine()) != null){
                char[]ss = str.toCharArray();
                for(int i = 0;i<ss.length;i++,a++){
                    dict[a] = ss[i];
                }
            }
            br.close();
        }catch (Exception e){
            e.printStackTrace();
        }
        //读取result文件内容
        try{
            File resultFile = new File ("./result.txt");
            BufferedReader br2 = new BufferedReader(new FileReader(resultFile));
            String str2;
            while((str2 = br2.readLine()) != null){
                String[]ss = str2.split(" ");
                for(int i = 0;i<ss.length;i++){
                    int a = Integer.parseInt(ss[i]);
                    answer.append(dict[a]);
                }
            }
            System.out.print(answer);
            br2.close();
        }catch (Exception e){
            e.printStackTrace();
        }

        try {
            File answerFile = new File ("./answer.txt");
            BufferedWriter bw = new BufferedWriter(new FileWriter(answerFile));
            System.out.print(answer);
            bw.write(String.valueOf(answer));
            bw.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
