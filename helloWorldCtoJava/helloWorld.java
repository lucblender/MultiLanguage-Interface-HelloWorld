import org.json.JSONObject;
import org.json.XML;

public class helloWorld{
	public static void main(String[] args){
		System.out.println("-------\tJAVA Main Launch thread");
		TestThread t = new TestThread("Main JAVA Thread");
		t.start();
		
	}

	public static void XmlDlmsListener(String XmlString)
	{
		System.out.println("\n-------\tXmlDlmsListener");
		System.out.println(XmlToJson(XmlString));
		System.out.println("-------\tOut of XmlDlmsListener\n");
	}

	
	public static String XmlToJson(String XmlString)
	{
		try{
			JSONObject xmlJsonObj = XML.toJSONObject(XmlString);
			String jsonString = xmlJsonObj.toString(1);
			return jsonString;
		}catch(Exception e){
			e.printStackTrace();
		}
		return "Error";
	}

}

