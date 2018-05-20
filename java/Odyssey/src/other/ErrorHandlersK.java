package other;

public class ErrorHandlersK {

	public String createUserErrors(String Username, String Password, String RepPassword) {
		
		if(Username.equals("")) {
			return "Dont forget to create a Username!";
		}
		
		if(Password.equals("")) {
			return "Dont forget to create a Password!";
		}
		
		if(RepPassword.equals("")) {
			return "Dont forget to repeat youre Password!";

		}
		
		if(!Password.equals(RepPassword)) {
			return "Ups! Password doesnt mach with the repeated password";
		}
		
				
		return "good";
	}
	
	
	
public String loadUserError(String Username, String Password) {
		
		if(Username.equals("")) {
			return "Please enter username!";
		}
		
		if(Password.equals("")) {
			return "Please enter password!";
		}
				
		return "good";
	}
	
	
	
}
