package xml.stax.model;

import java.io.FileOutputStream;
import javax.xml.stream.XMLEventWriter;
import javax.xml.stream.XMLEventFactory;
import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.Characters;
import javax.xml.stream.events.EndElement;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.StartDocument;
import javax.xml.stream.events.XMLEvent;


public class writer {
	 private String configFile;

	    public void setFile(String configFile) {
	        this.configFile = configFile;
	    }

	    public void saveConfig(String song, String gender, String artist, String album, String year, String lyrics,
				String category, int ope) throws Exception {
	        // create an XMLOutputFactory
	        XMLOutputFactory outputFactory = XMLOutputFactory.newInstance();
	        // create XMLEventWriter
	        XMLEventWriter eventWriter = outputFactory.createXMLEventWriter(new FileOutputStream(configFile));
	        // create an EventFactory
	        XMLEventFactory eventFactory = XMLEventFactory.newInstance();
	        XMLEvent end = eventFactory.createDTD("\n");
	        // create and write Start Tag
	        StartDocument startDocument = eventFactory.createStartDocument();
	        eventWriter.add(startDocument);

	        // create config open tag
	        StartElement configStartElement = eventFactory.createStartElement("",
	                "", "Data");
	        eventWriter.add(configStartElement);
	        eventWriter.add(end);
	        // Write the different nodes
	        createMusic(eventFactory, eventWriter, song, gender, artist, album, year, lyrics, category);
	        CreateOperative(eventWriter, ope);
	        eventWriter.add(eventFactory.createEndElement("", "", "Data"));
	        eventWriter.add(end);
	        eventWriter.add(eventFactory.createEndDocument());
	        eventWriter.close();
			
	    }
	    private void createMusic(XMLEventFactory node, XMLEventWriter eventWriter, String song, String genero, String Artist, String Album, String year, String Lyrics, String Category) throws XMLStreamException {
	    	XMLEvent ens = node.createDTD("\n");
	    	XMLEvent tab = node.createDTD("\t");
	    	StartElement sElem = node.createStartElement("", "", "Music");
	        Attribute prueba = node.createAttribute("nombre",song);
	        eventWriter.add(tab);
	        eventWriter.add(sElem);
	        eventWriter.add(prueba);
	        createChild(eventWriter, "Gender", genero);
	        createChild(eventWriter, "Artist", Artist);
	        createChild(eventWriter, "Album", Album);
	        createChild(eventWriter, "Year", year);
	        createChild(eventWriter, "Category", Category);
	        createChild(eventWriter, "Lyrics", Lyrics);
	       
	        EndElement eElement = node.createEndElement("","", "Music");
	        eventWriter.add(ens);
	        eventWriter.add(eElement);
	        
	    }
	    private void createChild(XMLEventWriter eventWriter, String name, String value) throws XMLStreamException {

	        XMLEventFactory eventFactory = XMLEventFactory.newInstance();
	        XMLEvent end = eventFactory.createDTD("\n");
	        XMLEvent tab = eventFactory.createDTD("\t");
	        // create Start node
	        StartElement sElement = eventFactory.createStartElement("", "", name);
	        eventWriter.add(tab);
	        eventWriter.add(sElement);
	        // create Content
	        Characters characters = eventFactory.createCharacters(value);
	        eventWriter.add(characters);
	        // create End node
	        EndElement eElement = eventFactory.createEndElement("", "", name);
	        eventWriter.add(eElement);
	        eventWriter.add(end);

}
	    private XMLEventFactory createNode(XMLEventWriter eventWriter, String name) throws XMLStreamException {

	        XMLEventFactory eventFactory = XMLEventFactory.newInstance();
	        XMLEvent en = eventFactory.createDTD("\n");
	        XMLEvent tab = eventFactory.createDTD("\t");
	        // create Start node
	        StartElement sElement = eventFactory.createStartElement("", "", name);
	        eventWriter.add(tab);
	        eventWriter.add(sElement);
	        EndElement element = eventFactory.createEndElement("", "","Cdata");
	        eventWriter.add(en);
	        eventWriter.add(element);
	        
			return eventFactory;

	    }
	    public void CreateOperative(XMLEventWriter eventWriter, int ope) throws XMLStreamException {
	    	 XMLEventFactory eventFactory = XMLEventFactory.newInstance();
		        XMLEvent end = eventFactory.createDTD("\n");
		        XMLEvent tab = eventFactory.createDTD("\t");
		        // create Start node
		        StartElement sElement = eventFactory.createStartElement("", "","apCode");
		        eventWriter.add(tab);
		        eventWriter.add(sElement);
		        // create Content
		        String str = Integer.toString(ope);
		        Characters characters = eventFactory.createCharacters(str);
		        eventWriter.add(characters);
		        // create End node
		        EndElement eElement = eventFactory.createEndElement("", "", "apCode");
		        eventWriter.add(eElement);
		        eventWriter.add(end);
	    }

		
}
