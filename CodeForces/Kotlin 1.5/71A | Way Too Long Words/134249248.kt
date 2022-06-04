 fun main() {
    repeat(readLine()!!.toInt()){
        var s = readLine()!!;
        if(s.length > 10){
            println("${s[0]}${s.length - 2}${s[s.length - 1]}");
        }else{
            println(s);
        }
    }
}