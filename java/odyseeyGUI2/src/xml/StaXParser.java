package xml;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.EndElement;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;


public class StaXParser {
	static final String NAME = "nombre";
	static final String MUSIC = "Music";
	static final String GENDER = "Gender";
	static final String ARTIST = "Artist";
	static final String ALBUM = "Album";
	static final String YEAR = "Year";
	static final String CATEGORY = "Category";
	static final String LYRICS = "Lyrics";
	static final String APCODE = "apCode";

	@SuppressWarnings({ "unchecked", "null" })
	public List<Item> readConfig(String configFile) {
		List<Item> items = new ArrayList<Item>();
		try {
			// First, create a new XMLInputFactory
			XMLInputFactory inputFactory = XMLInputFactory.newInstance();
			// Setup a new eventReader
			InputStream in = new FileInputStream(configFile);
			XMLEventReader eventReader = inputFactory.createXMLEventReader(in);
			// read the XML document
			Item item = null;

			while (eventReader.hasNext()) {
				XMLEvent event = eventReader.nextEvent();

				if (event.isStartElement()) {
					StartElement startElement = event.asStartElement();
					// If we have an item element, we create a new item

					if (startElement.getName().getLocalPart().equals(MUSIC)) {
						item = new Item();
						// We read the attributes from this tag and add the date
						// attribute to our object
						Iterator<Attribute> attributes = startElement
								.getAttributes();
						while (attributes.hasNext()) {
							Attribute attribute = attributes.next();
							if (attribute.getName().toString().equals(NAME)) {
								item.setDate(attribute.getValue());
							}

						}
					}

					if (event.isStartElement()) {
						if (event.asStartElement().getName().getLocalPart()
								.equals(GENDER)) {
							event = eventReader.nextEvent();
							item.setMode(event.asCharacters().getData());
							continue;
						}
					}
					if (event.asStartElement().getName().getLocalPart()
							.equals(ARTIST)) {
						event = eventReader.nextEvent();
						item.setUnit(event.asCharacters().getData());
						continue;
					}

					if (event.asStartElement().getName().getLocalPart()
							.equals(ALBUM)) {
						event = eventReader.nextEvent();
						item.setCurrent(event.asCharacters().getData());
						continue;
					}

					if (event.asStartElement().getName().getLocalPart()
							.equals(YEAR)) {
						event = eventReader.nextEvent();
						item.setInteractive(event.asCharacters().getData());
						continue;
					}
					if (event.asStartElement().getName().getLocalPart()
							.equals(CATEGORY)) {
						event = eventReader.nextEvent();
						item.setInteractive(event.asCharacters().getData());
						continue;
					}
					if (event.asStartElement().getName().getLocalPart()
							.equals(LYRICS)) {
						event = eventReader.nextEvent();
						item.setInteractive(event.asCharacters().getData());
						continue;
					}
				}
				// If we reach the end of an item element, we add it to the list
				if (event.isEndElement()) {
					EndElement endElement = event.asEndElement();
					if (endElement.getName().getLocalPart().equals(MUSIC)) {
						items.add(item);
					}
				}

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (XMLStreamException e) {
			e.printStackTrace();
		}
		return items;
	}
	public String getName(String XMLFile) {
		XMLInputFactory inputFactory = XMLInputFactory.newInstance();
		// Setup a new eventReader
		InputStream in = null;
		String name = null;
		try {
			in = new FileInputStream(XMLFile);
			XMLEventReader eventReader = inputFactory.createXMLEventReader(in);
			//XMLEvent event = eventReader.nextEvent();
			while (eventReader.hasNext()) {
				XMLEvent event = eventReader.nextEvent();
					if (event.isStartElement()) {
						StartElement startElement = event.asStartElement();
						name = startElement.getName().getLocalPart().toString();
						return name;
					}
				}
			} catch (XMLStreamException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return name;
		}
	}
