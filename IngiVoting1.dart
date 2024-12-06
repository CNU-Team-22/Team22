import 'package:flutter/material.dart';

void main() {
  runApp(
      MaterialApp(
          home: MyApp()
      )
  ); //runApp 앱시작하기
}

class MyApp extends StatefulWidget {  //stless  //앱 메인페이지 만드는 법
  MyApp({Key? key}) : super(key:key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  var name = [];
  var like = [];

  addName(String data){
    setState(() {
      name.add(data);
      like.add(1);
    });
  }

  addOne(int i){
    setState(() {
      like[i]++;
    });
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
        floatingActionButton: FloatingActionButton(
          onPressed: (){
            showDialog(context: context, builder: (context){
              return DialogUI(addOne : addOne, addName : addName);
            });
          },
        ),

        appBar: AppBar(
          backgroundColor: Colors.blue,
          title: Text("누가 가장 인기가 많을까요??"),
        ),

        body: ListView.builder(
          itemCount: name.length,
          itemBuilder: (context, i){
            return ListTile(
              leading: Text(like[i].toString()),
              title: Text(name[i]),
              trailing: TextButton(
                  onPressed: () {setState(() {like[i]++;});},
                  child: Text("좋아요")
              ),
            );
          },
        )
    );
  }
}

class DialogUI extends StatelessWidget {
  DialogUI({Key? key, this.addOne, this.addName }):super(key:key);
  final addOne;
  final addName;

  String str = "";

  @override
  Widget build(BuildContext context) {
    return Dialog(
        child: SizedBox(
            width: 412, height: 180,
            child: Column(
              children: [
                Text("누구를 투표하실 건가요?"),
                TextField(onChanged: (text) {
                  str = text;
                },),
                TextButton(
                    child: Text('추가'),
                    onPressed: (){
                      if(!str.isEmpty){
                        addName(str);
                        Navigator.pop(context);
                      }
                    }
                ),
                TextButton(
                  child: Text('취소'),
                  onPressed: (){
                    Navigator.pop(context);
                  }
                ),
              ],
            )
        )
    );
  }
}
