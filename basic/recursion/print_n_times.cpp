vector<string> printNTimes(int n) {

	if (n==1){

          return {"Coding Ninjas"};

        } 

	else {

          vector<string> arr = printNTimes(n - 1);

          arr.push_back("Coding Ninjas");

		  return arr;

        }

}
