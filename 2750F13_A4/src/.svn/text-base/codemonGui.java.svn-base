package codemonPkg4.JFurlone.A4;

import java.awt.FlowLayout;
import java.awt.BorderLayout;
import javax.swing.SpringLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.PrintWriter;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.util.*;
import java.util.prefs.*;
import java.util.ArrayList;
import java.io.*;

import javax.swing.*;
import java.awt.*;
import java.sql.*;

class paintLoop extends Thread
{
	codemonGui cdmG;
	int flag;
	int speed;
	JList reportList;
	String reportsPath;
	/*Colors*/
	Color Splinter = new Color (120,120,120);
	Color Shredder = new Color (169,169,169);
	Color TMNT = new Color (30,119,39);
	Color Donatello = new Color(148,20,255);
	Color Raphael = new Color(220,0,30);
	Color Leonardo = new Color(0,80,255);
	Color Michelangelo = new Color (210,95,0);
	
	public paintLoop (){}
	
	public void run()
	{
		
		String turnNum = new String();
		String playerNum = new String();
		String threadNum = new String();
		String c1 = new String();
		String c2 = new String();
		String c3 = new String();
		String c4 = new String();
		String selectedFile = new String();
		if(reportList.getSelectedValue() != null)
		{
			selectedFile = reportList.getSelectedValue().toString();
		}
			
		BufferedReader reader = null;
		String reportFile = new String(reportsPath + File.separator + selectedFile);
		File report_File = new File(reportFile);
		
		System.out.println("The reportFile: " + reportFile);
		
		try
		{
			String currentLine = new String();
			String[] tokenArray = new String[50];
			int t = 0;
			int count = 0;
			
				
			reader = new BufferedReader(new FileReader(reportFile));
			int kill = 0;
			int ink = 0;
			while(kill != 1)
			{
				System.out.println(flag);
				try
				{
					Thread.sleep(1);
				}
				catch (InterruptedException e)
				{
					System.out.println("Error with Thread.sleep1");
					e.printStackTrace();
				}
				while(flag != 1)
				{
					//System.out.println(currentLine);
					
					try
					{
						Thread.sleep(speed);
					}
					catch (InterruptedException e)
					{
						System.out.println("Error with Thread.sleep2");
						e.printStackTrace();
					}
					
					currentLine = reader.readLine();
					//System.out.println("INK: " +ink);
					if(currentLine.contains("PC="))
					{
						//System.out.println(tokenArray.length);
						int changer = 0;
						turnNum = currentLine.substring(1,6);
						playerNum = currentLine.substring(7,8);
						threadNum = currentLine.substring(9,10);
						tokenArray = currentLine.split("'");
						int tLength = 0;
						tLength = tokenArray.length;
					//	System.out.println("'tLength: " + tLength);
					//	System.out.println("turnNum: " + turnNum + " playerNum: " + playerNum + " threadNum: " + threadNum + " c1: ." + c1 + " c2: ." + c2 + " c3: ." + c3 + " c4: ." + c4);
					/*	for(int j = 0; j < tokenArray.length; j++)
						{
							System.out.println(tokenArray[j] + " token #" + j +"\n");
						}*/
						int cA = 0, cB = 0, cC = 0, cD = 0;
						if(threadNum.equals("1"))
						{
							Donatello = new Color(148,20,200);
							Raphael = new Color(170,0,0);
							Leonardo = new Color(0,80,230);
							Michelangelo = new Color (240,95,0);
						}
						else if(threadNum.equals("2"))
						{
							Donatello = new Color(190,40,200);
							Raphael = new Color(255,0,0);
							Leonardo = new Color(0,0,230);
							Michelangelo = new Color (200,150,0);
						}
						else if(threadNum.equals("3"))
						{
							Donatello = new Color(200,100,255);
							Raphael = new Color(255,0,50);
							Leonardo = new Color(20,100,255);
							Michelangelo = new Color (255,170,0);
						}
						if(tLength == 2)
						{
							c1 = tokenArray[1].substring(0,4);
							cA = Integer.parseInt(c1);
							if(playerNum.equals("1"))
							{
								cdmG.ChangeColor(cA, Michelangelo);
							}
							else if(playerNum.equals("2"))
							{
								cdmG.ChangeColor(cA, Donatello);
							}
							else if(playerNum.equals("3"))
							{
								cdmG.ChangeColor(cA, Raphael);
							}
							else if(playerNum.equals("4"))
							{
								cdmG.ChangeColor(cA, Leonardo);
							}
							//System.out.println("turnNum: " + turnNum + " playerNum: " + playerNum + " threadNum: " + threadNum + " c1: ." + c1);
						}
						else if(tLength == 3)
						{
							c1 = tokenArray[1].substring(0,4);
							c2 = tokenArray[2].substring(0,4);
							cA = Integer.parseInt(c1);
							cB = Integer.parseInt(c2);
							if(playerNum.equals("1"))
							{
								cdmG.ChangeColor(cB, Michelangelo);
							}
							else if(playerNum.equals("2"))
							{
								cdmG.ChangeColor(cB, Donatello);
							}
							else if(playerNum.equals("3"))
							{
								cdmG.ChangeColor(cB, Raphael);
							}
							else if(playerNum.equals("4"))
							{
								cdmG.ChangeColor(cB, Leonardo);
							}
							
							//System.out.println("turnNum: " + turnNum + " playerNum: " + playerNum + " threadNum: " + threadNum + " c1: ." + c1 + " c2: ." + c2);
						}
						else if(tLength == 4)
						{
							c1 = tokenArray[1].substring(0,4);
							c2 = tokenArray[2].substring(0,4);
							c3 = tokenArray[3].substring(0,4);
							cA = Integer.parseInt(c1);
							cB = Integer.parseInt(c2);
							cC = Integer.parseInt(c3);
							
							if(playerNum.equals("1"))
							{
								cdmG.ChangeColor(cC, Michelangelo);
							}
							else if(playerNum.equals("2"))
							{
								cdmG.ChangeColor(cC, Donatello);
							}
							else if(playerNum.equals("3"))
							{
								cdmG.ChangeColor(cC, Raphael);
							}
							else if(playerNum.equals("4"))
							{
								cdmG.ChangeColor(cC, Leonardo);
							}
							
							//System.out.println("turnNum: " + turnNum + " playerNum: " + playerNum + " threadNum: " + threadNum + " c1: ." + c1 + " c2: ." + c2 + " c3: ." + c3);
						}
						else if(tLength == 5)
						{
							c1 = tokenArray[1].substring(0,4);
							c2 = tokenArray[2].substring(0,4);
							c3 = tokenArray[3].substring(0,4);
							c4 = tokenArray[4].substring(0,4);
							cA = Integer.parseInt(c1);
							cB = Integer.parseInt(c2);
							cC = Integer.parseInt(c3);
							cD = Integer.parseInt(c4);
							
							if(playerNum.equals("1"))
							{
								cdmG.ChangeColor(cD, Michelangelo);
							}
							else if(playerNum.equals("2"))
							{
								cdmG.ChangeColor(cD, Donatello);
							}
							else if(playerNum.equals("3"))
							{
								cdmG.ChangeColor(cD, Raphael);
							}
							else if(playerNum.equals("4"))
							{
								cdmG.ChangeColor(cD, Leonardo);
							}
							
							
							
							//System.out.println("turnNum: " + turnNum + " playerNum: " + playerNum + " threadNum: " + threadNum + " c1: ." + c1 + " c2: ." + c2 + " c3: ." + c3 + " c4: ." + c4);
						}
						/*							
						for(int j = 0; j < tokenArray.length; j++)
						{
							System.out.println(tokenArray[j] + " token #" + j);
						}*/
						
						
						//addGet = Integer.parseInt(adds[count]);
						//System.out.println("Address is: " + addGet);
						//labelList.get(addGet).setOpaque(true);
						//panelList.get(addGet).setBackground(Raphael);
							
						//cdmG.ChangeColor(addGet, Raphael);
						//visualFrame.repaint();
						count++;
					}
					if(currentLine.contains("MEMORY DATA"))
					{
						kill = 1;
						break;
					}
					ink++;
				}
			}
			
		}
		catch (IOException e)
		{
			System.out.println("Exception! Play..");
			e.printStackTrace();
		}
		finally
		{
			try 
			{
				if (reader != null)reader.close();
				//System.out.println("DAFAQQQ!!!");
				this.stop();
			} 
			catch (IOException ex) 
			{
				System.out.println("Exception! Closing! Play..");
				ex.printStackTrace();
			}
			
			
		}
	}
	
}

class WriteFile 
{
    private String path;
    private boolean append_to_file = false;

    public WriteFile (String file_path)
    {
        path = file_path;
    }

    public WriteFile(String file_path, boolean append_value)
    {
        path = file_path;
        append_to_file = append_value;
    }
    
    public void writeToFile (String textLine) throws IOException
    {
        FileWriter write = new FileWriter (path, append_to_file);
        PrintWriter print_line = new PrintWriter(write);
        print_line.printf("%s" + "%n", textLine);
        print_line.close();
    }
}


public class codemonGui extends JFrame
{
	
	Preferences pathConfig = Preferences.userNodeForPackage(this.getClass());
	
	static
	{
		System.loadLibrary("codemonCompiler");
	}
	
	native int JavaCompileFile(String filename, String pathToSave);
	native int JavaLexxYaccCompile(String filename, String pathToSave);
	native int JavaTestCodemon(String codemon1, String iteration);
	native int JavaSelfCodemon(String codemon1, String codemon2, String iteration);
	native int JavaRunPvp(String codemon1, int pvp);
	native int JavaGetReport(int repoID, String reportFile);
	
	/*Boolean*/
	boolean changed;
	
	
	/*JComboBoxes*/
	JComboBox codemonBox1 = new JComboBox();
	JComboBox codemonBox2 = new JComboBox();
	
	/*JFileChooser*/
	JFileChooser fileChooser = new JFileChooser();
	JFileChooser codemonChooser = new JFileChooser();
	
	/*JButtons*/
	
	/*MainFrame JButtons*/
	JButton trainButton = new JButton("Train");
	JButton fightButton = new JButton("Fight");
	JButton historyButton = new JButton("History");
	JButton fillerButton = new JButton("Filler");
	JButton exitButton = new JButton("Exit");
	JButton aboutButton = new JButton("About");
	
	/*TrainFrame JButtons*/
	JButton newButton = new JButton("New");
	JButton openButton = new JButton("Open");
	JButton saveButton = new JButton("Save");
	JButton saveasButton = new JButton("Save As..");
	JButton quitButton = new JButton("Quit");
	
	/*FightFrame JButtons*/
	JButton runTestButton = new JButton();
	JButton runSelfButton = new JButton();
	JButton runPvpButton = new JButton();
	JButton deleteButton = new JButton();
	JButton visualButton = new JButton();
	
	/*Visual Frame Buttons*/
	JButton play = new JButton();
	JButton fast = new JButton();
	JButton slow = new JButton();

	/*JFrames*/
	JFrame fightFrame = new JFrame();
	JFrame trainFrame = new JFrame();
	JFrame helpFrame = new JFrame();
	JFrame quickViewFrame = new JFrame();
	JFrame reportFrame = new JFrame();
	JFrame visualFrame = new JFrame();
	JFrame historyFrame = new JFrame();
	
	/*JLabels*/
	JLabel welcomeLabel = new JLabel();
	JLabel authorLabel = new JLabel("CIS*2750F13 - Author John M Furlone");
	JLabel chooseCodemon1 = new JLabel("Codemon1: ");
	JLabel chooseCodemon2 = new JLabel("Codemon2: ");
	JLabel modifiedLabel = new JLabel();
	/*Visual Labels*/
	JLabel Player1 = new JLabel("Player 1");
	JLabel Player2 = new JLabel("Player 2");
	JLabel Player3 = new JLabel("Player 3");
	JLabel Player4 = new JLabel("Player 4");
	JLabel name1 = new JLabel("#");
	JLabel name2 = new JLabel("#");
	JLabel name3 = new JLabel("#");
	JLabel name4 = new JLabel("#");
	JLabel lines1 = new JLabel("~");
	JLabel lines2 = new JLabel("~");
	JLabel lines3 = new JLabel("~");
	JLabel lines4 = new JLabel("~");
	
	/*JMenuBars*/
	JMenuBar fightMenuBar = new JMenuBar();
	JMenuBar trainMenuBar = new JMenuBar();
	
	/*JMenus*/
	/*Train Menus*/
	JMenu trainFileMenu = new JMenu();
	JMenu trainBuildMenu = new JMenu();
	JMenu trainConfigMenu = new JMenu();
	JMenu trainHelpMenu = new JMenu();
	
	/*Fight Menus*/
	JMenu fightConfigMenu = new JMenu();
	JMenu fightReportsMenu = new JMenu();
	JMenu fightHelpMenu = new JMenu();	
	JMenu fightVsMenuItems = new JMenu();
	
	/*JMenuItems*/
	/*Train Items*/
	JMenuItem newMenuItem = new JMenuItem();
	JMenuItem openMenuItem = new JMenuItem();
	JMenuItem saveMenuItem = new JMenuItem();
	JMenuItem saveasMenuItem = new JMenuItem();
	JMenuItem quitMenuItem = new JMenuItem();
	
	JMenuItem assembleMenuItem = new JMenuItem();
	JMenuItem a_LaunchMenuItem = new JMenuItem();
	
	JMenuItem sourceDirMenuItem = new JMenuItem();
	JMenuItem codemonDirMenuItem = new JMenuItem();
	
	JMenuItem helpMenuItem = new JMenuItem();
	
	/*Fight Items*/
	JMenuItem fightSourceDirMenuItem = new JMenuItem();
	JMenuItem fightCodemonDirMenuItem = new JMenuItem();
	JMenuItem fightReportsDirMenuItem = new JMenuItem();
	JMenuItem fightVisualMenuItem = new JMenuItem();
	JMenuItem fightHistoryMenuItem = new JMenuItem();
	JMenuItem fightIterationMenuItem = new JMenuItem();
	JRadioButtonMenuItem vs1 = new JRadioButtonMenuItem("PVP2", true);
	JRadioButtonMenuItem vs2 = new JRadioButtonMenuItem("PVP3", false);
	JRadioButtonMenuItem vs3 = new JRadioButtonMenuItem("PVP4", false);
	
	JMenuItem fightViewReportMenuItem = new JMenuItem();
	JMenuItem fightDeleteReportMenuItem = new JMenuItem();
	JMenuItem fightFetchReportsMenuItem = new JMenuItem();
	
	JMenuItem fightHelpMenuItem = new JMenuItem();
		
	/*JPanels*/
	/*Main Panels*/
	JPanel mainPanel = new JPanel();
	JPanel welcomePanel = new JPanel();
	JPanel mainButtonPanel = new JPanel();
	JPanel authorPanel = new JPanel();
	/*Train Panels*/
	JPanel trainPanel = new JPanel();
	JPanel trainButtonPanel = new JPanel();
	JPanel trainTextPanel = new JPanel();
	JPanel trainModifiedPanel = new JPanel();
	/*Fight Panels*/
	JPanel fightPanel = new JPanel();
	JPanel fightButtonPanel = new JPanel();
	JPanel fightReportPanel = new JPanel();
	JPanel fightChooseViewPanel = new JPanel();
	JPanel fightViewPanel = new JPanel();
	JPanel fightChoosePanel = new JPanel();
		/*QuickViewFrame Panel*/
		JPanel qViewPanel = new JPanel();
		/*Report Frame Panel*/
		JPanel reportPanel = new JPanel();
	/*Help Panels*/
	JPanel helpPanel = new JPanel();
	
	/*Visual Panels*/
	JPanel visualPanel = new JPanel();
	JPanel streetFightPanel = new JPanel();
	JPanel shells = new JPanel();
	JPanel hubPanel = new JPanel();
	JPanel commandCenter = new JPanel();
	JPanel Raph = new JPanel();
	JPanel Mikey = new JPanel();
	JPanel Leo = new JPanel();
	JPanel Donnie = new JPanel();
	
	
	
	/*JScrollPanes*/
	JScrollPane jScrollPane1 = new JScrollPane();
	JScrollPane jScrollPane2 = new JScrollPane();
	JScrollPane jScrollPane3 = new JScrollPane();
	JScrollPane jScrollPaneQview = new JScrollPane();
	JScrollPane jScrollPaneQFrame = new JScrollPane();
	JScrollPane jScrollPaneRepoFrame = new JScrollPane();
	
	/*JTextArea*/
	/*TrainFrame Text*/
	JTextArea textArea = new JTextArea();
	
	/*FightFrame Text*/
	JTextArea reportArea = new JTextArea();
	
	/*HelpFrame Text*/
	JTextArea helpArea = new JTextArea();
	
	Color bluegray = new Color(90,135,150);
	
	/*QuickViewFrame Text*/
	JTextArea qViewArea = new JTextArea();
	
	/*JString*/
	String sourcePath = new String();
	String codemonPath = new String();
	String reportsPath = new String();
	String rootPath = new String();
	String imagePath = new String();
	String currentFileName = new String();
	String file_name = new String();
	
	
	/*Visual Strings*/
	String playerID = new String();
	String address = new String();
	String codemonName = new String();
	String lineToken = new String();
	String [] players = new String[4];
	String [] adds = new String[4];
	String [] codemons = new String[4];
	String [] lines = new String[4];
	
	/*Colors*/
	Color Splinter = new Color (120,120,120);
	Color Shredder = new Color (169,169,169);
	Color TMNT = new Color (30,119,39);
	Color Donatello = new Color(148,20,255);
	Color Raphael = new Color(220,0,30);
	Color Leonardo = new Color(0,80,255);
	Color Michelangelo = new Color (210,95,0);


	
	/*JList*/
	JList sourceList = new JList();
	static JList reportList = new JList();
	
	/*JToolBar*/
	JToolBar trainToolBar = new JToolBar();
	JToolBar fightToolBar = new JToolBar();
	
	//Pvp and interation
	String iteration = new String("1");
	int pvp = 2;
	
	/*AboutFrame*/
	JFrame aboutFrame = new JFrame();
	JPanel aboutPanel = new JPanel();
	JTextField aboutArea = new JTextField();
	JScrollPane scrollAbout = new JScrollPane();
	
	/*ARRAYLIST*/
	static ArrayList<JPanel> panelList = new ArrayList<JPanel>(4095);
	
	/*Visual Flag*/
	int pop = 1;
	int increment = 10;
	int inital = 100;
	
	/*Stuffs*/
	paintLoop Painter;
	Thread threadIt = new Thread();
	
	/*History/SQL stuff*/
	/*History Frame*/
	JButton histGamesButton = new JButton("Games");
	JButton histTrainerButton = new JButton("Trainers");
	JButton histCodemonButton = new JButton("Codemon");
	
	JPanel mainHistPanel = new JPanel();
	
	
	
	/*SQL*/
	String createCodemonTable = new String("CREATE TABLE Codemon (Codemon_Name VARCHAR(25), Source VARCHAR(600))");
	String createTrainerTable = new String("CREATE TABLE Trainers (Trainer_Name VARCHAR(25) NOT NULL, Trainer_Num DECIMAL(2) NOT NULL, PRIMARY KEY(Trainer_Name))");	
	String createGamesTable = new String("null");
	
	Connection conn = null;
	Connection conn2 = null;
	Statement stmt = null;
	Statement stmt2 = null;
	ResultSet rsQuery = null;
	ResultSet printQuery = null;
	DatabaseMetaData dbm = null;
	String sqlJarfile = new String();
	
	
	public codemonGui()
	{
		if(pathConfig.get("SOURCE", null) == null)
		{
			pathConfig.put("SOURCE", (System.getProperty("user.dir") + "/Source"));
		}
		else
		{
			sourcePath = pathConfig.get("SOURCE", "");
		}
		
		if(pathConfig.get("CODEMON", null) == null)
		{
			pathConfig.put("CODEMON", (System.getProperty("user.dir") + "/Codemon"));
		}
		else
		{
			codemonPath = pathConfig.get("CODEMON", "");
		}
		
		if(pathConfig.get("REPORTS", null) == null)
		{
			pathConfig.put("REPORTS", (System.getProperty("user.dir") + "/Reports"));
		}
		else
		{
			reportsPath = pathConfig.get("REPORTS", "");
		}
		
		if(pathConfig.get("ROOT", null) == null)
		{
			pathConfig.put("ROOT", (System.getProperty("user.dir")));
		}
		else
		{
			rootPath = pathConfig.get("ROOT", "");
		}
		
		System.out.println(sourcePath);
		System.out.println(codemonPath);
		System.out.println(reportsPath);
		System.out.println(rootPath);
		
		/*SQL DATA GRAB*/
		sqlJarfile = rootPath + File.separator + "mysql.jar";
		System.out.println(sqlJarfile);
		
		try{
			
				Class.forName("com.mysql.jdbc.Driver");
			
				final String USER = "jfurlone";
				final String PASS = "0661197";
				final String DB_URL = "jdbc:mysql://eon.socs.uoguelph.ca/jfurlone";
				System.out.println("Connecting to database...");
				conn = DriverManager.getConnection(DB_URL,USER,PASS);
			
				System.out.println("Creating statement...");
				stmt = conn.createStatement();
				dbm = conn.getMetaData();
				

				createCodemonTable = "CREATE TABLE Codemon (Codemon_Name VARCHAR(25), Source VARCHAR(600))";
				createTrainerTable = "CREATE TABLE Trainers (Trainer_Name VARCHAR(25) NOT NULL, Number INTEGER(2) NOT NULL, PRIMARY KEY (Trainer_Name))";

				/*Check for Trainers Table*/
				rsQuery = dbm.getTables(null,null,"Trainers", null);
				if(!rsQuery.next())
				{
					stmt.executeUpdate(createTrainerTable);
					System.out.println("Creating Trainers table!");
				}
				else
				{
					System.out.println("Trainer table already exists!");
				}
				
				/*Check for Codemon Table*/
				rsQuery = dbm.getTables(null,null,"Codemon", null);
				if(!rsQuery.next())
				{
					stmt.executeUpdate(createCodemonTable);
					System.out.println("Creating Codemon table!");
				}
				else
				{
					System.out.println("Codemon table already exists!");
				}
				//createGamesTable = "CREATE TABLE Games (Result VARCHAR(25), Source VARCHAR(600))";
				
				printQuery = stmt.executeQuery("SELECT * FROM Trainers");
				
				
				while(printQuery.next())
				{
					//Retrieve by column name
					int num = printQuery.getInt("Number");
					String Name = printQuery.getString("Trainer_Name");
					//Display values
					System.out.print("Number: " + num);
					System.out.print(", Trainer_Name: " + Name + "\n");
				}
				
				rsQuery.close();
				printQuery.close();
				stmt.close();
				conn.close();
			}
			catch (SQLException se)
			{
				//Errors for JDBC
				se.printStackTrace();
			}
			catch(Exception e)
			{
				//Handle errors for Class.forName
				e.printStackTrace();
			}
			finally
			{
				//finally block used to close resources
				try
				{
					if(stmt!=null)
					stmt.close();
				}
				catch(SQLException se2)
				{
				
				}// nothing we can do
				try
				{
					if(conn!=null)
					conn.close();
				}
				catch(SQLException se)
				{
					se.printStackTrace();
				}//end finally try
			}//end try
		
		/*Making Main Panel*/
		mainPanel.setLayout(new BorderLayout(10,10));
		
		/*Panel to hold Welcome Label*/
		welcomePanel.setPreferredSize(new Dimension(390,275));
		
		/*Making Welcome Label*/
		welcomeLabel.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "Char_izard.gif"));
	//	welcomeLabel.setHorizontalAlignment(0);
		welcomePanel.add(welcomeLabel);
		mainPanel.add(welcomePanel, BorderLayout.NORTH);
		
		/*Main Button Panel*/
		mainButtonPanel.setLayout(new GridLayout(2,3,10,10));
		mainButtonPanel.setPreferredSize(new Dimension(400, 200));
		
		/*Making trainButton*/
		trainButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent evt) 
			{
				mainActionPerformed(evt);
			}
		});
			
		mainButtonPanel.add(trainButton);
		
		/*Filler for nicer display*/
		fillerButton.setVisible(false);
		mainButtonPanel.add(fillerButton);
		
		/*Making fightButton*/
		fightButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent evt) 
			{
				mainActionPerformed(evt);
			}
		});
		
		mainButtonPanel.add(fightButton);
		
		/*Making historyButton*/
		historyButton.addActionListener(new ActionListener ()
		{
			public void actionPerformed (ActionEvent evt)
			{
				historyActionPerformed(evt);
			}
		});
		
		mainButtonPanel.add(historyButton);
		
		/*Making aboutButton*/
		aboutButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent evt) 
			{
				mainActionPerformed(evt);
			}
		});
		
		mainButtonPanel.add(aboutButton);
		
		
		/*Making exitButton*/
		exitButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent evt) 
			{
				mainActionPerformed(evt);
			}
		});
		
		mainButtonPanel.add(exitButton);
		mainPanel.add(mainButtonPanel, BorderLayout.CENTER);
		
		/*authorPanel*/
		authorPanel.setPreferredSize(new Dimension (600,30));
		authorPanel.add(authorLabel);
		mainPanel.add(authorPanel, BorderLayout.SOUTH);
		
		this.add(mainPanel);
		
		
		
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~Fight Frame~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		fightFrame.setTitle("FIGHT!!!");
		fightFrame.setLayout(new BorderLayout (10,10));
		fightFrame.setSize(640,800);
		fightFrame.addWindowListener(new WindowAdapter() {
		@Override
		public void windowClosing (WindowEvent w)
		{
			fightButton.setEnabled(true);
		}
		});
		
		/*Fight Menu Bar*/
		/*Fight ConfigMenu Items*/
		fightConfigMenu.setMnemonic('c');
		fightConfigMenu.setText("Config");
		
		fightSourceDirMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_D,  InputEvent.CTRL_MASK));
        fightSourceDirMenuItem.setText("Source Directory: " + sourcePath);
        fightSourceDirMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        fightCodemonDirMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_D,  InputEvent.ALT_MASK | InputEvent.CTRL_MASK));
        fightCodemonDirMenuItem.setText("Codemon Directory: " +  codemonPath);
        fightCodemonDirMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        fightReportsDirMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_R,  InputEvent.CTRL_MASK));
        fightReportsDirMenuItem.setText("Reports Directory: " + reportsPath);
        fightReportsDirMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        
        fightIterationMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_I,  InputEvent.CTRL_MASK));
        fightIterationMenuItem.setText("Iteration Limit");
        fightIterationMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        
        fightVsMenuItems.setMnemonic(KeyEvent.VK_V);
        fightVsMenuItems.setText("Versus...");
        
        vs1.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        vs2.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        vs3.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        ButtonGroup pvpGroup = new ButtonGroup();
        pvpGroup.add(vs1);
        pvpGroup.add(vs2);
        pvpGroup.add(vs3);
        fightVsMenuItems.add(vs1);
        fightVsMenuItems.add(vs2);
        fightVsMenuItems.add(vs3);
        
        /*Add to FightConfigMenu*/
        fightConfigMenu.add(fightSourceDirMenuItem);
        fightConfigMenu.add(fightCodemonDirMenuItem);
        fightConfigMenu.add(fightReportsDirMenuItem);
        fightConfigMenu.add(fightIterationMenuItem);
        fightConfigMenu.add(fightVsMenuItems);
        
        /*Fight Reports MenuItem*/
        fightReportsMenu.setMnemonic('r');
		fightReportsMenu.setText("Reports");
        
        fightViewReportMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_V,  InputEvent.CTRL_MASK));
        fightViewReportMenuItem.setText("View");
        fightViewReportMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        
        fightDeleteReportMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_E,  InputEvent.CTRL_MASK));
        fightDeleteReportMenuItem.setText("Delete");
        fightDeleteReportMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        
        fightFetchReportsMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_F,  InputEvent.CTRL_MASK));
        fightFetchReportsMenuItem.setText("Fetch all");
        fightFetchReportsMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
        
        fightVisualMenuItem.setAccelerator(KeyStroke.getKeyStroke( KeyEvent.VK_Y,  InputEvent.CTRL_MASK));
        fightVisualMenuItem.setText("Visualize");
        fightVisualMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                visualActionPerformed(evt);
            }
        });
        
        fightHistoryMenuItem.setAccelerator(KeyStroke.getKeyStroke( KeyEvent.VK_H,  InputEvent.CTRL_MASK));
        fightHistoryMenuItem.setText("History");
        fightHistoryMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                historyActionPerformed(evt);
            }
        });
        
        /*Add to FightReportsMenu*/
        fightReportsMenu.add(fightViewReportMenuItem);
        fightReportsMenu.add(fightDeleteReportMenuItem);
        fightReportsMenu.add(fightFetchReportsMenuItem);
        fightReportsMenu.add(fightVisualMenuItem);
        fightReportsMenu.add(fightHistoryMenuItem);
        
    	/*Fight Help MenuItems*/
        fightHelpMenu.setMnemonic('h');
		fightHelpMenu.setText("Help!");
        
    	fightHelpMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_H,  InputEvent.CTRL_MASK));
        fightHelpMenuItem.setText("Help Me!");
        fightHelpMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                mainActionPerformed(evt);
            }
        });
        
        /*Add to FightHelpMenu*/
		fightHelpMenu.add(fightHelpMenuItem);
		
		/*Add to FightMenuBar and Set to Frame*/
        fightMenuBar.add(fightConfigMenu);
        fightMenuBar.add(fightReportsMenu);
        fightMenuBar.add(fightHelpMenu);
        fightFrame.setJMenuBar(fightMenuBar);
        
        /*Fight Panel*/
        fightPanel.setLayout(new BorderLayout(10,10));
        
        /*Fight Button Panel*/
        //fightButtonPanel.setLayout(new FlowLayout());
        //fightButtonPanel.setPreferredSize (new Dimension(600,100));
        //fightToolBar.setPreferredSize (new Dimension(500,50));
        
        /*Fight Buttons*/
        runTestButton.setSize(40,40);
        runTestButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "runtest.png"));
        runTestButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                fightActionPerformed(evt);
            }
        });
		//fightButtonPanel.add(runTestButton);
		fightToolBar.add(runTestButton);
		
        runSelfButton.setSize(40,40);
        runSelfButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "runself.png"));
		runSelfButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
             {
                 fightActionPerformed(evt);
             }
         });
         //fightButtonPanel.add(runSelfButton);
         fightToolBar.add(runSelfButton);
 		
 		runPvpButton.setSize(40,40);
        runPvpButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "runpvp.png"));
 		runPvpButton.addActionListener(new ActionListener() 
         {
             public void actionPerformed( ActionEvent evt) 
             {
                 fightActionPerformed(evt);
             }
         });
 		//fightButtonPanel.add(runPvpButton);
 		fightToolBar.add(runPvpButton);
 		
 		deleteButton.setSize(40,40);
        deleteButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "delete.png"));
 		deleteButton.addActionListener(new ActionListener() 
         {
             public void actionPerformed( ActionEvent evt) 
             {
                 fightActionPerformed(evt);
             }
         });
 		//fightButtonPanel.add(deleteButton);
 		fightToolBar.add(deleteButton);
        
        visualButton.setSize(40,40);
        visualButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "visual.png"));
 		visualButton.addActionListener(new ActionListener() 
         {
             public void actionPerformed( ActionEvent evt) 
             {
                 visualActionPerformed(evt);
             }
         });
        fightToolBar.add(visualButton);
        
        //fightButtonPanel.add(fightToolBar);
        
        fightPanel.add(fightToolBar, BorderLayout.NORTH);
        
        /*Fight ReportPanel*/
        fightReportPanel.setLayout(new BorderLayout(10,10));
		fightReportPanel.setBorder(BorderFactory.createTitledBorder("Reports"));
		fightReportPanel.setPreferredSize(new Dimension (275,495));
        
      /*  reportArea.setColumns(20);
        reportArea.setLineWrap(true);
        reportArea.setRows(5);
        reportArea.setWrapStyleWord(true);
        reportArea.setEditable(false);
        reportArea.setPreferredSize(getMaximumSize());*/
        
        String reportFiles = new String();
		File reportFolder = new File(reportsPath);
		File[] listOfReports = reportFolder.listFiles(); 
 		String [] reportStrings = new String [listOfReports.length];
 		int repoCount = 0;
 		
		for (int i = 0; i < listOfReports.length; i++) 
		{
			if (listOfReports[i].isFile()) 
			{
				reportFiles = listOfReports[i].getName();
			   	if (reportFiles.endsWith(".reportID"))
			   	{
			   		reportStrings[repoCount] = reportFiles;
					//System.out.println("Report Files: "+reportStrings[repoCount]);
					repoCount++;
				}
			}
		}
		
		
		reportList = new JList(reportStrings);
		reportList.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		reportList.setPreferredSize(new Dimension(350,495));
		reportList.setLayoutOrientation(JList.VERTICAL);
		reportList.addMouseListener(new MouseAdapter() {
		public void mouseClicked ( MouseEvent click)
		{
			String selectedFile = new String();
			selectedFile = reportList.getSelectedValue().toString();
			if(click.getClickCount() == 2)
			{
				reportFrame.setTitle(selectedFile);
				reportFrame.setLayout(new BorderLayout (10,10));
				reportFrame.setSize(400,400);
				
				reportPanel.setLayout(new BorderLayout(10,10));
				reportPanel.setBorder(BorderFactory.createTitledBorder("Report view for " + selectedFile));
				//System.out.println(initLocation + "readMe");
					
				reportArea.setColumns(20);
				reportArea.setLineWrap(true);
				reportArea.setRows(5);
				reportArea.setWrapStyleWord(true);
				reportArea.setEditable(false);
				reportArea.setPreferredSize(getMaximumSize());	
				jScrollPaneRepoFrame.setViewportView(reportArea);
				
				reportArea.setLocation(0,0);
				reportPanel.add(jScrollPaneRepoFrame, BorderLayout.CENTER);
				reportArea.setVisible(true);
				
				File repo_File = new File(reportsPath + File.separator + selectedFile);
				fileChooser.setSelectedFile(repo_File);
				try 
				{
					reportArea.read( new FileReader( repo_File.getAbsolutePath() ), null );
					System.out.println("File Opened: ~" + repo_File.toString() + "~");
				}   
				catch (IOException ex) 
				{
					System.out.println("problem accessing file"+repo_File.getAbsolutePath());
				}
				
				reportFrame.add(reportPanel, BorderLayout.CENTER);
				reportFrame.setVisible(true);
			}
		}
		});
        
        jScrollPane2.setViewportView(reportList);
        
        
		fightReportPanel.add(jScrollPane2, BorderLayout.CENTER);
		reportArea.setVisible(true);
		
		fightPanel.add(fightReportPanel, BorderLayout.EAST);
        
        /*Fight Choose + View Panel*/
        fightChooseViewPanel.setLayout(new BorderLayout(10,10));
		
		
		/*FightChoosePanel*/
		fightChoosePanel.setLayout(new GridLayout (2,2,10,10));
		fightChoosePanel.setPreferredSize (new Dimension(365,100));
		fightChoosePanel.setBorder(BorderFactory.createTitledBorder("I choose you..."));
		
		
		fightChoosePanel.add(chooseCodemon1);
		fightChoosePanel.add(codemonBox1);
		fightChoosePanel.add(chooseCodemon2);
		fightChoosePanel.add(codemonBox2);
		
		fightChooseViewPanel.add(fightChoosePanel, BorderLayout.NORTH);
		
		/*FightViewPanel*/
		fightViewPanel.setBorder(BorderFactory.createTitledBorder("Quick View"));
		fightViewPanel.setPreferredSize(new Dimension(365,500));
		
		//qViewArea.setColumns(20);
        //qViewArea.setLineWrap(true);
        //qViewArea.setRows(5);
        //qViewArea.setEditable(false);
        //qViewArea.setWrapStyleWord(true);
        //qViewArea.setPreferredSize(new Dimension(350,495));
        //qViewArea.setLocation(0,0);
		//qViewArea.setVisible(true);
        
        String sourceFiles = new String();
		File folder = new File(sourcePath);
		File[] listOfFiles = folder.listFiles(); 
 		String [] sourceStrings = new String [listOfFiles.length];
 		int srcCount = 0;
 		
		for (int i = 0; i < listOfFiles.length; i++) 
		{
			if (listOfFiles[i].isFile()) 
			{
				sourceFiles = listOfFiles[i].getName();
			   	if (sourceFiles.endsWith(".cm"))
			   	{
			   		sourceStrings[srcCount] = sourceFiles;
					System.out.println(sourceStrings[srcCount]);
					srcCount++;
				}
			}
		}
		
		
		sourceList = new JList(sourceStrings);
		sourceList.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		sourceList.setPreferredSize(new Dimension(350,495));
		sourceList.setLayoutOrientation(JList.VERTICAL);
		sourceList.addMouseListener(new MouseAdapter() {
			public void mouseClicked ( MouseEvent click)
			{
				String selectedFile = new String();
				selectedFile = sourceList.getSelectedValue().toString();
				if(click.getClickCount() == 2)
				{
					quickViewFrame.setTitle(selectedFile);
					quickViewFrame.setLayout(new BorderLayout (10,10));
					quickViewFrame.setSize(400,400);
					
					qViewPanel.setLayout(new BorderLayout(10,10));
					qViewPanel.setBorder(BorderFactory.createTitledBorder("Quick View for " + selectedFile));
								
					//System.out.println(initLocation + "readMe");
								
					qViewArea.setColumns(20);
					qViewArea.setLineWrap(true);
					qViewArea.setRows(5);
					qViewArea.setWrapStyleWord(true);
					qViewArea.setEditable(false);
					qViewArea.setPreferredSize(getMaximumSize());
					jScrollPaneQFrame.setViewportView(qViewArea);
					
					qViewArea.setLocation(0,0);
					qViewPanel.add(jScrollPaneQFrame, BorderLayout.CENTER);
					qViewArea.setVisible(true);
					
					File qV_File = new File(sourcePath + File.separator + selectedFile);
					fileChooser.setSelectedFile(qV_File);
					try 
					{
						qViewArea.read( new FileReader( qV_File.getAbsolutePath() ), null );
						System.out.println("File Opened: ~" + qV_File.toString() + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem accessing file"+qV_File.getAbsolutePath());
					}
					
					quickViewFrame.add(qViewPanel, BorderLayout.CENTER);
					quickViewFrame.setVisible(true);
				}
			}
		});
	//	sourceList.setVisibleRowCount(10);
		jScrollPaneQview.setPreferredSize(new Dimension(350,495));
		jScrollPaneQview.setViewportView(sourceList);
        
		
		fightViewPanel.add(jScrollPaneQview);
		
		fightChooseViewPanel.add(fightViewPanel, BorderLayout.CENTER);
		
		fightPanel.add(fightChooseViewPanel, BorderLayout.WEST);
        
		fightFrame.add(fightPanel);
		
		
		
		
		
		
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~Train Frame~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
		trainFrame.setTitle("TRAIN!!!");
		trainFrame.setLayout(new BorderLayout (10,10));
		trainFrame.setSize(640,800);
		trainFrame.addWindowListener(new WindowAdapter() {
		@Override
		public void windowClosing (WindowEvent w)
		{
			trainButton.setEnabled(true);
		}
		});
		
		/*Train Panel*/
		trainPanel.setLayout(new BorderLayout(10,10));
		
		/*Train Button Panel*/
		//trainButtonPanel.setLayout(new GridLayout(0,5,10,10));
		//trainButtonPanel.setPreferredSize(new Dimension(600, 100));
		//trainToolBar.setPreferredSize(new Dimension(500, 50));
		
		/*Train Buttons*/
		newButton.setSize(40,40);
        newButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "new.png"));
		newButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent e) 
			{
				trainActionPerformed(e);
			}
		});
		//trainButtonPanel.add(newButton);
		trainToolBar.add(newButton);
		
		openButton.setSize(40,40);
        openButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "open.png"));
		openButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent e) 
			{
				trainActionPerformed(e);
			}
		});
		//trainButtonPanel.add(openButton);
		trainToolBar.add(openButton);
		
		saveButton.setSize(40,40);
        saveButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "save.png"));
		saveButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent e) 
			{
				trainActionPerformed(e);
			}
		});
		//trainButtonPanel.add(saveButton);
		trainToolBar.add(saveButton);
		
		saveasButton.setSize(40,40);
        saveasButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "saveas.png"));
		saveasButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent e) 
			{
				trainActionPerformed(e);
			}
		});
		//trainButtonPanel.add(saveasButton);
		trainToolBar.add(saveasButton);
		
		quitButton.setSize(40,40);
        quitButton.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "quit.png"));
		quitButton.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent e) 
			{
				trainActionPerformed(e);
			}
		});
		//trainButtonPanel.add(quitButton);
		trainToolBar.add(quitButton);
		
		//trainPanel.add(trainButtonPanel, BorderLayout.NORTH);
		trainPanel.add(trainToolBar, BorderLayout.NORTH);
		/*Train Text Panel*/
		
		trainTextPanel.setLayout(new BorderLayout(10,10));
		trainTextPanel.setBorder(BorderFactory.createTitledBorder("TitledBorder"));
//		trainButtonPanel.setPreferredSize(new Dimension(600, 500));
		
		/*Train Text Area*/
		textArea.getDocument().addDocumentListener( new DocumentListener ()
		{
			public void changedUpdate (DocumentEvent e) 
			{
				isModifiedActionPerformed(e);
			}
			public void removeUpdate (DocumentEvent e) 
			{
				isModifiedActionPerformed(e);
			}
			public void insertUpdate (DocumentEvent e) 
			{
				isModifiedActionPerformed(e);
			}
		});
		textArea.setColumns(20);
        textArea.setLineWrap(true);
        textArea.setRows(5);
        textArea.setWrapStyleWord(true);
  		//textArea.setBorder(BorderFactory.createTitledBorder("TitledBorder"));
        textArea.setPreferredSize(getMaximumSize());
        jScrollPane1.setViewportView(textArea);
		
		textArea.setLocation(0,0);
		trainTextPanel.add(jScrollPane1, BorderLayout.CENTER);
		textArea.setVisible(true);
		
		trainPanel.add(trainTextPanel, BorderLayout.CENTER);
		
		/*Train Modified Panel*/
		trainModifiedPanel.setPreferredSize(new Dimension(600,30));
		trainModifiedPanel.add(modifiedLabel);
		
		trainPanel.add(trainModifiedPanel, BorderLayout.SOUTH);
		
		trainFrame.add(trainPanel);
		
		/*Train Menu Bar*/
		
		/*FileMenu Items*/
		trainFileMenu.setMnemonic('f');
		trainFileMenu.setText("File");
		
		newMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_N,  InputEvent.CTRL_MASK));
        //newMenuItem.setMnemonic('n');
        newMenuItem.setText("New");
        newMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        openMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_O,  InputEvent.CTRL_MASK));
        //openMenuItem.setMnemonic('o');
        openMenuItem.setText("Open");
        openMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        saveMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_S,  InputEvent.CTRL_MASK));
       // saveMenuItem.setMnemonic('s');
        saveMenuItem.setText("Save");
        saveMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        saveasMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_S, InputEvent.ALT_MASK | InputEvent.CTRL_MASK));
       // saveasMenuItem.setMnemonic('v');
        saveasMenuItem.setText("Save As...");
        saveasMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        quitMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_Q, InputEvent.CTRL_MASK));
       // quitMenuItem.setMnemonic('q');
        quitMenuItem.setText("Quit...");
        quitMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        /*Add to FileMenu*/
        trainFileMenu.add(newMenuItem);
        trainFileMenu.add(openMenuItem);
        trainFileMenu.add(saveMenuItem);
        trainFileMenu.add(saveasMenuItem);
        trainFileMenu.add(quitMenuItem);
        
        /*Build Menu Items*/
        trainBuildMenu.setMnemonic('b');
		trainBuildMenu.setText("Build");
        
        assembleMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_A,  InputEvent.CTRL_MASK));
       // assembleMenuItem.setMnemonic('a');
        assembleMenuItem.setText("Assemble");
        assembleMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        a_LaunchMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_A, InputEvent.ALT_MASK | InputEvent.CTRL_MASK));
        //a_LaunchMenuItem.setMnemonic('l');
        a_LaunchMenuItem.setText("Assemble and Launch");
        a_LaunchMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        /*Add to BuildMenu*/
        trainBuildMenu.add(assembleMenuItem);
        trainBuildMenu.add(a_LaunchMenuItem);
        
        
        /*Config Menu Items*/
        trainConfigMenu.setMnemonic('c');
		trainConfigMenu.setText("Config");
        
        sourceDirMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_D,  InputEvent.CTRL_MASK));
       // sourceDirMenuItem.setMnemonic('');
        sourceDirMenuItem.setText("Source Directory: " + sourcePath);
        sourceDirMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        codemonDirMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_D, InputEvent.ALT_MASK | InputEvent.CTRL_MASK));
        //codemonDirMenuItem.setMnemonic('l');
        codemonDirMenuItem.setText("Codemon Directory: " +  codemonPath);
        codemonDirMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                trainActionPerformed(evt);
            }
        });
        
        /*Add to ConfigMenu*/
        trainConfigMenu.add(sourceDirMenuItem);
        trainConfigMenu.add(codemonDirMenuItem);
        
        
        /*Help Menu Items*/
        trainHelpMenu.setMnemonic('h');
		trainHelpMenu.setText("Help!");
        
    	helpMenuItem.setAccelerator( KeyStroke.getKeyStroke( KeyEvent.VK_H,  InputEvent.CTRL_MASK));
       // sourceDirMenuItem.setMnemonic('');
        helpMenuItem.setText("Help Me!");
        helpMenuItem.addActionListener(new ActionListener() 
        {
            public void actionPerformed( ActionEvent evt) 
            {
                mainActionPerformed(evt);
            }
        });
        
        /*Add to HelpMenu*/
        trainHelpMenu.add(helpMenuItem);
        
        /*Add to trainMenuBar and Set to Frame*/
        trainMenuBar.add(trainFileMenu);
        trainMenuBar.add(trainBuildMenu);
        trainMenuBar.add(trainConfigMenu);
        trainMenuBar.add(trainHelpMenu);
        trainFrame.setJMenuBar(trainMenuBar);
        
        
        
        
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~Visual Frame~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		visualFrame.setTitle(">~Visualize~<");
		visualFrame.setLayout(new BorderLayout (10,10));
		visualFrame.setSize(1200,600);
		visualFrame.addWindowListener(new WindowAdapter() {
		@Override
		public void windowClosing (WindowEvent w)
		{
			visualButton.setEnabled(true);
			Painter.stop();
			play.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "play.png"));
			pop = 1;
			Painter.flag = 1;
		}
		});
		
		/*Visual Panel*//*TMNT for labels*/
		visualPanel.setLayout(new BorderLayout(10,10));
		visualPanel.setBackground(Shredder);
		
		/*streetFightPanel*/
		streetFightPanel.setLayout(new GridLayout(32,128,3,3));
		streetFightPanel.setPreferredSize(getMaximumSize());
		streetFightPanel.setBackground(Shredder);
		
		play.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "play.png"));
    	play.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent v) 
			{
				visualActionPerformed(v);
			}
		});
		
		
		fast.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "fast.png"));
    	fast.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent v) 
			{
				visualActionPerformed(v);
			}
		});
		
		slow.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "slow.png"));
    	slow.addActionListener(new ActionListener () 
		{
			public void actionPerformed (ActionEvent v) 
			{
				visualActionPerformed(v);
			}
		});
		
		for(int i = 0; i < 4096; i++)
		{
			shells = new JPanel();
			//shells.setOpaque(true);
			//shells.setBackground(TMNT);
			panelList.add(shells);
			ChangeColor(i,TMNT);
			streetFightPanel.add(shells);
		}
		
		
		
		/*hubPanel*//*Add other panels to hub panel, then hub to Visual*/
		hubPanel.setLayout(new GridLayout(0,5,3,3));
		hubPanel.setPreferredSize(new Dimension(600, 250));
		hubPanel.setBackground(Color.black);
		
		/*Turtle Panels*/
		Mikey.setLayout(new GridLayout(2,2,15,15));
		
		Mikey.add(Player1);
		Mikey.add(name1);
		Mikey.add(lines1);
		
		Mikey.setBackground(Michelangelo);
		Donnie.setLayout(new GridLayout(2,2,15,15));
		
		Donnie.add(Player2);
		Donnie.add(name2);
		Donnie.add(lines2);
		
		Donnie.setBackground(Donatello);
		Leo.setLayout(new GridLayout(2,2,15,15));
		
		Leo.add(Player3);
		Leo.add(name3);
		Leo.add(lines3);
		
		Leo.setBackground(Leonardo);
		Raph.setLayout(new GridLayout(2,2,15,15));
		
		Raph.add(Player4);
		Raph.add(name4);
		Raph.add(lines4);
		
		Raph.setBackground(Raphael);
		/*commandCenter Panel*//*uses picture*/
    	commandCenter.setBackground(Splinter);
    	commandCenter.setLayout(new BorderLayout(10,10));
		commandCenter.add(play, BorderLayout.CENTER);
		commandCenter.add(slow, BorderLayout.SOUTH);
		commandCenter.add(fast, BorderLayout.NORTH);
		/*commandCenter.setLayout(new GridLayout(3,0,10,10));
		commandCenter.add(fast);
		commandCenter.add(play);
		commandCenter.add(slow);
    	*/
    	
    	
    	hubPanel.add(Mikey);
        hubPanel.add(Donnie);
        hubPanel.add(commandCenter);
        hubPanel.add(Raph);
        hubPanel.add(Leo);
        
        visualPanel.add(streetFightPanel, BorderLayout.CENTER);
        visualPanel.add(hubPanel, BorderLayout.SOUTH);
        
        visualFrame.add(visualPanel);
        
        
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /*~~~~~~~~~~~~History Frame~~~~~~~~~~~~*/
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		historyFrame.setTitle(">~History~<");
		historyFrame.setLayout(new BorderLayout (10,10));
		historyFrame.setSize(900,600);
		historyFrame.addWindowListener(new WindowAdapter() {
		@Override
		public void windowClosing (WindowEvent w)
		{
			historyButton.setEnabled(true);
			fightHistoryMenuItem.setEnabled(true);
		}
		});
        
        
        
        
	}
	
	
	public void historyActionPerformed(ActionEvent h)
	{
		if(h.getSource() == historyButton || h.getSource() == fightHistoryMenuItem)
		{
			historyFrame.setVisible(true);
			fightHistoryMenuItem.setEnabled(false);
			historyButton.setEnabled(false);
		}
		
	}
	
	public void getCodemonDirFiles()
	{
		String codemonFiles = new String();
		String [] codemonStrings = new String [50];
		File folder = new File(codemonPath);
		File[] listOfFiles = folder.listFiles(); 
 
		for (int i = 0; i < listOfFiles.length; i++) 
		{
			if (listOfFiles[i].isFile()) 
			{
				codemonFiles = listOfFiles[i].getName();
			   	if (codemonFiles.endsWith(".codemon"))
			   	{
			   		String noExtension = new String(codemonFiles.substring(0,codemonFiles.lastIndexOf('.')));
			   		codemonStrings[i] = noExtension;
					System.out.println(codemonStrings[i]);
				}
			}
		}
		
		codemonBox1.setModel( new DefaultComboBoxModel(codemonStrings));
		codemonBox2.setModel( new DefaultComboBoxModel(codemonStrings));
	}
	
	public void getSourceDirFiles()
	{
		String sourceFiles = new String();
		String [] sourceStrings = new String [50];
		File folder = new File(sourcePath);
		File[] listOfFiles = folder.listFiles(); 
 
		for (int i = 0; i < listOfFiles.length; i++) 
		{
			if (listOfFiles[i].isFile()) 
			{
				sourceFiles = listOfFiles[i].getName();
			   	if (sourceFiles.endsWith(".cm"))
			   	{
			   		sourceStrings[i] = sourceFiles;
					System.out.println(sourceStrings[i]);
				}
			}
		}
		
		sourceList.setListData(sourceStrings);
	}
	
	public void getReportFiles(int insFlag)
	{
		
		String [] trainers = new String [4];
		String [] codemonsH = new String [4];
		String [] results = new String[4];
		String temp = new String();
		
		String reportFiles = new String();
		File reportFolder = new File(reportsPath);
		File[] listOfReports = reportFolder.listFiles(); 
 		String [] reportStrings = new String [listOfReports.length];
 		int repoCount = 0;
 		
		for (int i = 0; i < listOfReports.length; i++) 
		{
			if (listOfReports[i].isFile()) 
			{
				reportFiles = listOfReports[i].getName();
			   	if (reportFiles.endsWith(".reportID"))
			   	{
			   		reportStrings[repoCount] = reportFiles;
					System.out.println("Report Files: "+reportStrings[repoCount]);
					repoCount++;
				}
			}
		}
		
		//Create else statement for deletion of a report... maybe?
		if(insFlag == 0)
		{
			ResultSet trainQuery = null;
			ResultSet trainNumQuery = null;
			ResultSet codeQuery = null;
			Random generator = new Random(19580427);
			
			try{
			
					Class.forName("com.mysql.jdbc.Driver");
			
					final String user = "jfurlone";
					final String pass = "0661197";
					final String db_url = "jdbc:mysql://eon.socs.uoguelph.ca/jfurlone";
					System.out.println("Connecting to database...");
					conn = DriverManager.getConnection(db_url,user,pass);
					conn2 = DriverManager.getConnection(db_url,user,pass);
					
					System.out.println("Creating statement...");
					stmt = conn.createStatement();
					stmt2 = conn2.createStatement();
				
					String selectedFile = new String();
					BufferedReader reader = null;
					String reportFile = null;
					File report_File = null;
					int z = 0;
					int rand = 0;
					while(z < reportStrings.length - 1)
					{
			
						selectedFile = reportStrings[z];
						System.out.println("\n~~~~~~~~~~\n"+reportStrings[z]+"\n~~~~~~~~~~\n");
			
						//String selectedFile = new String(reportList.getSelectedValue().toString());
						reportFile = new String(reportsPath + File.separator + selectedFile);
						//System.out.println("Visual is looking in: "+reportFile);
						report_File = new File(reportFile);
	
						try
						{
							String currentLine;
							String[] tokenArray = new String[50];
							int t = 0;
							int count = 0;
		
							reader = new BufferedReader(new FileReader(reportFile));
		
							while((currentLine = reader.readLine()) != null)
							{
								if(currentLine.contains("you..."))
								{
									tokenArray = currentLine.split(" ");
			//						if(tokenArray[0].equals(">"))
			//						{
										playerID = new String(tokenArray[1]);
										//System.out.println("playerID: "+ playerID);
										int length = tokenArray[3].length();
										codemonName = new String(tokenArray[3].substring(1,length-1));
										//System.out.println("codemonName: "+ codemonName);
			//						}
									trainers[count] = playerID;
									codemonsH[count] = codemonName;
									//System.out.println("Trainers: " + trainers[count]);
									//System.out.println("Codemon: " + codemonsH[count] + "\nCount: " + count + "\n");
									count++;							
								}
								else if(currentLine.contains(">>>"))
								{
									int xz = 0;
									while(xz < count)
									{
										System.out.println("Trainers: " + trainers[xz]);
										System.out.println("Codemon: " + codemonsH[xz] + "\nCount: " + xz + "\n");
										
										/*At this point we have all the Trainer and Codemon names for the single match.
										So now we can probably do a check to see if we can add them to the database
										e.g. make sure there are no duplicates.
										*/
										trainQuery = stmt.executeQuery("SELECT Trainer_Name FROM Trainers;");
										trainNumQuery = stmt2.executeQuery("SELECT Number FROM Trainers;");
										while(trainQuery.next())
										{
											String tName = trainQuery.getString("Trainer_Name");
											if(!tName.equals(trainers[xz]))
											{
											/*THIS WONT WORK DIPSHIT
											the values of one does not determine if the values of the rest are not the same.*/
												while(trainNumQuery.next())
												{
													int tNum = trainNumQuery.getInt("Number");
													rand = tNum;
													while(rand == tNum)
													{
														rand = generator.nextInt(200);
													}
													if(rand != tNum)
													{
														stmt.executeUpdate("INSERT INTO Trainers (Trainer_Name, Number) VALUES (\"" + trainers[xz] + "\", \""+ rand +"\");");
													}
													//need to create statement for == and when Trainer is the same
												}
											}
											else
											{
												System.out.println( trainers[xz] + " is a already exists,\nany value to be associated with this Trainer should be stored in the Games Table");
											}
										}
										xz++;
									}
																		
									results [0] = reportStrings[z].substring(0,4);
									tokenArray = currentLine.split(" ");
									//System.out.println(tokenArray[0]);
									//System.out.println(tokenArray[1]);
									//System.out.println(tokenArray[2]);
									
									int length2 = tokenArray[1].length();
									temp = new String(tokenArray[1].substring(0,length2-1));
									results[1] = temp;
									temp = new String(tokenArray[2]);
									
									tokenArray = temp.split("-");
									//System.out.println(tokenArray[0]);
									//System.out.println(tokenArray[1]);
									
									length2 = tokenArray[0].length();
									temp = new String(tokenArray[0].substring(4,length2));
									results[2] = temp;
									temp = new String(tokenArray[1]);
									results[3] = temp;
									
									/*Because we know the names of the other Trainers/Codemon
									we can assume all have lost except for the Winner in this result
									UNLESS it is a TIE*/
									System.out.println("Results:\n"+results[0]);
									System.out.println(results[1]);
									System.out.println(results[2]);
									System.out.println(results[3]);
									
								}
							/*	if(count > 3)
								{
									break;
								}*/
							}
				/*
							for(int in = 0; in<count; in++)
							{
								
								//IF STATEMENT that checks for duplicates between array and table in database
								//
								//stmt.executeUpdate("INSERT INTO Trainers (Trainer_Name, Number) VALUES (\"" + trainers[in] + "\", 0 );");
								//trainQuery = stmt.executeQuery("SELECT Trainer_Name FROM Trainers WHERE Trainer_Name = \""+ trainers[in]+"\"");
		
								if()
								{
									stmt.executeUpdate("INSERT INTO Trainers (Trainer_Name, Number) VALUES (\"" + TrainerName + "\", " + Nums + ");");
								}
							
							}
				*/
						}
						catch (IOException e)
						{
							System.out.println("Exception!");
							e.printStackTrace();
						}
						finally
						{
							try 
							{
								if (reader != null)reader.close();
			
							} 
							catch (IOException ex) 
							{
								System.out.println("Exception! Closing!");
								ex.printStackTrace();
							}
						}
					z++;
					}//EndWhile
		
				
				
				
					trainQuery.close();
					trainNumQuery.close();
					stmt.close();
					stmt2.close();
					conn.close();
					conn2.close();
				}
				catch (SQLException se)
				{
					//Errors for JDBC
					se.printStackTrace();
				}
				catch(Exception e)
				{
					//Handle errors for Class.forName
					e.printStackTrace();
				}
				finally
				{
					//finally block used to close resources
					try
					{
						if(stmt!=null)
						stmt.close();
						
						if(stmt2!=null)
						stmt.close();
					}
					catch(SQLException se2)
					{
				
					}// nothing we can do
					try
					{
						if(conn!=null)
						conn.close();
						
						if(conn2!=null)
						conn2.close();
					}
					catch(SQLException se)
					{
						se.printStackTrace();
					}//end finally try
				}//end try
		}
		
		
		reportList.setListData(reportStrings);
	}
		
	public void isModifiedActionPerformed(DocumentEvent e)
	{
		System.out.println("It changed man!");
		changed = true;
		modifiedLabel.setText("Modified");
	}
	
	public void ChangeColor(int address, Color color)
	{		
	//panelList.remove(address);
	
	panelList.get(address).setBackground(color);
	
	}
	
	public void mainActionPerformed(ActionEvent e)
	{
		if(e.getSource() == trainButton)
		{
			trainButton.setEnabled(false);
			trainFrame.setVisible(true);
		}
		else if (e.getSource() == fightButton)
		{
			fightButton.setEnabled(false);
			fightFrame.setVisible(true);
			/*figntFrame.addWindowListener
			*/
		}
		else if (e.getSource() == exitButton)
		{
			welcomeLabel.setText("Peace.");
			System.exit(0);
		}
		else if (e.getSource() == aboutButton)
		{
			
			aboutFrame.setTitle("ReadMe");
			aboutFrame.setLayout(new BorderLayout (10,10));
			aboutFrame.setSize(400,400);
			
			helpPanel.setLayout(new BorderLayout(10,10));
			helpPanel.setBorder(BorderFactory.createTitledBorder("Help.."));
						
			//System.out.println(initLocation + "readMe");
						
			helpArea.setColumns(20);
			helpArea.setLineWrap(true);
			helpArea.setRows(5);
			helpArea.setWrapStyleWord(true);
			helpArea.setEditable(false);
			helpArea.setPreferredSize(getMaximumSize());
			jScrollPane3.setViewportView(helpArea);
			
			helpArea.setLocation(0,0);
			helpPanel.add(jScrollPane3, BorderLayout.CENTER);
			helpArea.setVisible(true);
			
			File help_File = new File(rootPath + File.separator + "readMe.txt");
			fileChooser.setSelectedFile(help_File);
			try 
			{
				helpArea.read( new FileReader( help_File.getAbsolutePath() ), null );
				System.out.println("File Opened: ~" + help_File.toString() + "~");
			}   
			catch (IOException ex) 
			{
				System.out.println("problem accessing file"+help_File.getAbsolutePath());
			}
			
			aboutFrame.add(helpPanel, BorderLayout.CENTER);
			aboutFrame.setVisible(true);
		}
		/*Help Window*/
		else if(e.getSource() == helpMenuItem || e.getSource() == fightHelpMenuItem)
		{
		
			helpFrame.setTitle("Help!");
			helpFrame.setLayout(new BorderLayout (10,10));
			helpFrame.setSize(400,400);
			
			helpPanel.setLayout(new BorderLayout(10,10));
			helpPanel.setBorder(BorderFactory.createTitledBorder("Help.."));
						
			//System.out.println(initLocation + "readMe");
						
			helpArea.setColumns(20);
			helpArea.setLineWrap(true);
			helpArea.setRows(5);
			helpArea.setWrapStyleWord(true);
			helpArea.setEditable(false);
			helpArea.setPreferredSize(getMaximumSize());
			jScrollPane3.setViewportView(helpArea);
			
			helpArea.setLocation(0,0);
			helpPanel.add(jScrollPane3, BorderLayout.CENTER);
			helpArea.setVisible(true);
			
			File help_File = new File(rootPath + File.separator + "helpFile.txt");
			fileChooser.setSelectedFile(help_File);
			try 
			{
				helpArea.read( new FileReader( help_File.getAbsolutePath() ), null );
				System.out.println("File Opened: ~" + help_File.toString() + "~");
			}   
			catch (IOException ex) 
			{
				System.out.println("problem accessing file"+help_File.getAbsolutePath());
			}
			
			helpFrame.add(helpPanel, BorderLayout.CENTER);
			helpFrame.setVisible(true);

		}
	}
	
	public void trainActionPerformed(ActionEvent t)
	{
		/*NEW*/
		if(t.getSource() == newMenuItem || t.getSource() == newButton)
		{
			if(changed == false)
			{
				System.out.println("It's all good!!");
				textArea.setText("");
				changed = false;
			}
			else
			{
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					currentFileName = new String(fileChooser.getName(saved_File));
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
						textArea.setText("");	
						System.out.println("File Saved as (New): ~" + currentFileName + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
		}
		/*OPEN*/
		else if(t.getSource() == openMenuItem || t.getSource() == openButton)
		{
			if(changed == true)
			{
				System.out.println("Save before opening a new one!");
				
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					currentFileName = new String(fileChooser.getName(saved_File));
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
						textArea.setText("");
						System.out.println("File Saved As (open): ~" + currentFileName + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
			else
			{
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				System.out.println(sourcePath);
				int returnVal = fileChooser.showOpenDialog(trainFrame);
				System.out.println("returnVal"+returnVal);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File file = fileChooser.getSelectedFile();
					file_name = file.toString();
					currentFileName = new String(fileChooser.getName(file));
					try 
					{
						// What to do with the file, e.g. display it in a TextArea
						//String allText = textArea.getText();
						textArea.read( new FileReader( file.getAbsolutePath() ), null );
						textArea.getDocument().addDocumentListener( new DocumentListener ()
						{
							public void changedUpdate (DocumentEvent e) 
							{
								isModifiedActionPerformed(e);
							}
							public void removeUpdate (DocumentEvent e) 
							{
								isModifiedActionPerformed(e);
							}
							public void insertUpdate (DocumentEvent e) 
							{
								isModifiedActionPerformed(e);
							}
						});
						
						System.out.println("File Opened: ~" + currentFileName + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem accessing file"+file.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}	
			}
		}
		/*SAVE*/
		else if(t.getSource() == saveMenuItem || t.getSource() == saveButton)
		{

			if(file_name.length() == 0)
			{
				System.out.println("File is untitled, save as function executed for filename");
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					currentFileName = new String(fileChooser.getName(saved_File));
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
			else if(changed == true && currentFileName.length() != 0)
			{
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath ));
				File saved_File = new File(file_name);
				fileChooser.setSelectedFile(saved_File);
				file_name = saved_File.toString();
				System.out.println("new file_name: " + file_name);
				currentFileName = new String(fileChooser.getName(saved_File));
				try 
				{
					WriteFile data = new WriteFile(file_name, false);
					String allText = textArea.getText();
					data.writeToFile(allText);
					System.out.println("File Saved as: ~" + currentFileName + "~");
				}   
				catch (IOException ex) 
				{
					System.out.println("problem saving file"+saved_File.getAbsolutePath());
				}
				changed = false;
				modifiedLabel.setText("");
			}
		}
		/*SAVE_AS*/
		else if((t.getSource() == saveasMenuItem) || (t.getSource() == saveasButton))
		{
			fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
			fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
			int returnVal = fileChooser.showSaveDialog(trainFrame);
			if (returnVal == JFileChooser.APPROVE_OPTION) 
			{
				File saved_File = fileChooser.getSelectedFile();
				file_name = saved_File.toString();
				currentFileName = new String(fileChooser.getName(saved_File));
				try 
				{
					WriteFile data = new WriteFile(file_name, false);
					String allText = textArea.getText();
					data.writeToFile(allText);
					System.out.println("File Saved as: ~" + currentFileName + "~");
				}   
				catch (IOException ex) 
				{
					System.out.println("problem saving file"+saved_File.getAbsolutePath());
				}
			} 
			else     
			{
				System.out.println("File access cancelled by user.");
			}
			changed = false;
			modifiedLabel.setText("");
		}
		/*QUIT*/
		else if(t.getSource() == quitMenuItem || t.getSource() == quitButton)
		{
			if(changed == true)
			{
				System.out.println("Save before closing frame!");
				
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
						textArea.setText("");
						System.out.println("File Saved as (Quit): ~" + currentFileName + "~");
						trainFrame.dispose();
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
			else
			{
				trainButton.setEnabled(true);
				trainFrame.dispose();
			}
		}
		/*ASSEMBLE*/
		else if(t.getSource() == assembleMenuItem)
		{
			if(changed == false)
			{
				
				String pathToFile1 = new String(sourcePath + File.separator + currentFileName);
				String pathToFile2 = new String(codemonPath + File.separator + currentFileName);
				System.out.println("Filename being sent to native: " +currentFileName);
				System.out.println("File path being sent to native: " +pathToFile1);
				System.out.println("File path being sent to native: " + pathToFile2);
				//JavaCompileFile(pathToFile1, pathToFile2);
				JavaLexxYaccCompile(pathToFile1, pathToFile2);
				getCodemonDirFiles();
				System.out.println("In java???\n");
			}
			else
			{
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					currentFileName = new String(fileChooser.getName(saved_File));
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
						System.out.println("File Saved as: ~" + currentFileName + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
		}
		/*ASSEMBLE and LAUNCH*/
		else if(t.getSource() == a_LaunchMenuItem)
		{
			//System.out.println("Filename being sent to native: " +currentFileName);
			//JavaCompileFile(file_name, codemonPath + File.separator + currentFileName);
			if (changed == false)
			{
				String pathToFile1 = new String(sourcePath + File.separator + currentFileName);
				String pathToFile2 = new String(codemonPath + File.separator + currentFileName);
				//JavaCompileFile(pathToFile1, pathToFile2);
				JavaLexxYaccCompile(pathToFile1, pathToFile2);
				getCodemonDirFiles();
				fightButton.setEnabled(false);
				fightFrame.setVisible(true);	
			}
			else
			{
				fileChooser.setFileFilter(new FileNameExtensionFilter("Cm Files","cm"));
				fileChooser.setCurrentDirectory(new File(sourcePath )); /*This is GOLD*/
				int returnVal = fileChooser.showSaveDialog(trainFrame);
				if (returnVal == JFileChooser.APPROVE_OPTION) 
				{
					File saved_File = fileChooser.getSelectedFile();
					file_name = saved_File.toString();
					currentFileName = new String(fileChooser.getName(saved_File));
					try 
					{
						WriteFile data = new WriteFile(file_name, false);
						String allText = textArea.getText();
						data.writeToFile(allText);
						System.out.println("File Saved as: ~" + currentFileName + "~");
					}   
					catch (IOException ex) 
					{
						System.out.println("problem saving file"+saved_File.getAbsolutePath());
					}
				} 
				else     
				{
					System.out.println("File access cancelled by user.");
				}
				changed = false;
				modifiedLabel.setText("");
			}
		}
		/*SOURCE DIRECTORY*/
		else if(t.getSource() == sourceDirMenuItem || t.getSource() == fightSourceDirMenuItem)
		{
			fileChooser.setCurrentDirectory(new File(sourcePath)); /*This is GOLD*/
			fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			int returnVal = fileChooser.showOpenDialog(trainFrame);
			if (returnVal == JFileChooser.APPROVE_OPTION) 
			{
				File newSource = fileChooser.getSelectedFile();
				sourcePath = newSource.getAbsolutePath().toString();
				System.out.println(sourcePath);
				sourceDirMenuItem.setText(sourcePath);
				fileChooser.setCurrentDirectory(new File(sourcePath));
			} 
			else     
			{
				System.out.println("File access cancelled by user.");
			}
			fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		}
		/*CODEMON DIRECTORY*/
		else if(t.getSource() == codemonDirMenuItem || t.getSource() == fightCodemonDirMenuItem)
		{
			fileChooser.setCurrentDirectory(new File(codemonPath)); /*This is GOLD*/
			fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			int returnVal = fileChooser.showOpenDialog(trainFrame);
			if (returnVal == JFileChooser.APPROVE_OPTION) 
			{
				File newCodemon = fileChooser.getSelectedFile();
				codemonPath = newCodemon.getAbsolutePath().toString();
				System.out.println(codemonPath);
				codemonDirMenuItem.setText(codemonPath);
				fileChooser.setCurrentDirectory(new File(codemonPath));
			} 
			else     
			{
				System.out.println("File access cancelled by user.");
			}
			fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		}
	//getSourceDirFiles();
	System.out.println("End of TrainListener!!\n\n");	
	}
	
	public void fightActionPerformed(ActionEvent f)
	{
		/*Reports Directory*/
		if(f.getSource() == fightReportsDirMenuItem)
		{
			fileChooser.setCurrentDirectory(new File(reportsPath)); /*This is GOLD*/
			fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			int returnVal = fileChooser.showOpenDialog(fightFrame);
			if (returnVal == JFileChooser.APPROVE_OPTION) 
			{
				File newReports = fileChooser.getSelectedFile();
				String reportsPath = newReports.getAbsolutePath().toString();
				System.out.println(reportsPath);
				fightReportsDirMenuItem.setText(reportsPath);
				fileChooser.setCurrentDirectory(new File(reportsPath));
			} 
			else     
			{
				System.out.println("File access cancelled by user.");
			}
		}
		/*RUN TEST*/
		else if(f.getSource() == runTestButton)
		{
			int reportID = 0;
			int getReportVal = 0;
			
			String file1 = new String();
			
			if(codemonBox1.getSelectedItem().toString() != null)
			{
				file1 = new String(codemonBox1.getSelectedItem().toString() + ".codemon");
			}
			
			String pathToFile3 = new String(codemonPath + File.separator + file1);
			//System.out.println("File path being sent to native: " +pathToFile3);
			reportID = JavaTestCodemon(pathToFile3, iteration);
			//System.out.println("Java's Report ID: " + reportID);
			String reportFile = new String(reportsPath + File.separator + reportID +".reportID");
			//System.out.println("Java's Report File: " + reportFile);
			
			try 
			{
				File report_File = new File(reportFile);
				if(report_File.exists())
				{
					System.out.println("File already exists.");	
				}
				else
				{
					report_File.createNewFile();
					System.out.println("File should be made.");
				}
			}   
			catch (IOException ex) 
			{
				System.out.println("problem creating file: "+ reportID +".reportID");
			}
			
			
			getReportVal = JavaGetReport(reportID, reportFile);
			System.out.println("Get report return: " + getReportVal);
			
			File report_File = new File(reportFile);
			if(getReportVal == 1)
			{
				getReportFiles(0);
			}
			else if(getReportVal == 0)
			{
				if(report_File.exists())
				{
					System.out.println("File already exists, therefore, delete.");	
					report_File.delete();
				}
				else
				{
					System.out.println("File doesn't exists, ...Issue!");
				}
			}
			
			
			
		}
		/*RUN SELF*/
		else if(f.getSource() == runSelfButton)
		{
			int reportID = 0;
			int getReportVal = 0;
			
			String file1 = new String();
			String file2 = new String();
			
			if(codemonBox1.getSelectedItem().toString() != null)
			{
				file1 = new String(codemonBox1.getSelectedItem().toString() + ".codemon");
			}
			
			if(codemonBox2.getSelectedItem().toString() != null)
			{
				file2 = new String(codemonBox2.getSelectedItem().toString() + ".codemon");
			}
			
			String pathToFile3 = new String(codemonPath + File.separator + file1);
			String pathToFile4 = new String(codemonPath + File.separator + file2);
		//	System.out.println("File path being sent to native: " +pathToFile3);
		//	System.out.println("File path being sent to native: " +pathToFile4);
			
			reportID = JavaSelfCodemon(pathToFile3, pathToFile4, iteration);
		//	System.out.println("Java's Report ID: " + reportID);
			String reportFile = new String(reportsPath + File.separator + reportID +".reportID");
		//	System.out.println("Java's Report File: " + reportFile);
			try 
			{
				File report_File = new File(reportFile);
				if(report_File.exists())
				{
					System.out.println("File already exists.");	
				}
				else
				{
					report_File.createNewFile();
					System.out.println("File should be made.");
				}
			}   
			catch (IOException ex) 
			{
				System.out.println("problem creating file: "+ reportID +".reportID");
			}
			
			
			getReportVal = JavaGetReport(reportID, reportFile);
			System.out.println("Get report return: " + getReportVal);
			
			File report_File = new File(reportFile);
			if(getReportVal == 1)
			{
				getReportFiles(0);
			}
			else if(getReportVal == 0)
			{
				if(report_File.exists())
				{
					System.out.println("File already exists, therefore, delete.");	
					report_File.delete();
				}
				else
				{
					System.out.println("File doesn't exists, ...Issue!");
				}
			}
			
			
		}
		/*RUN PVP*/
		else if(f.getSource() == runPvpButton)
		{
			int reportID = 0;
			int getReportVal = 0;
			
			String file1 = new String();
			
			if(codemonBox1.getSelectedItem().toString() != null)
			{
				file1 = new String(codemonBox1.getSelectedItem().toString() + ".codemon");
			}
			
			String pathToFile3 = new String(codemonPath + File.separator + file1);
			
			reportID = JavaRunPvp(pathToFile3, pvp);
			
			String reportFile = new String(reportsPath + File.separator + reportID +".reportID");
			
			try 
			{
				File report_File = new File(reportFile);
				if(report_File.exists())
				{
					System.out.println("File already exists.");	
				}
				else
				{
					report_File.createNewFile();
					System.out.println("File should be made.");
				}
			}   
			catch (IOException ex) 
			{
				System.out.println("problem creating file: "+ reportID +".reportID");
			}
			
			
			getReportVal = JavaGetReport(reportID, reportFile);
			System.out.println("Get report return: " + getReportVal);
			
			File report_File = new File(reportFile);
			if(getReportVal == 1)
			{
				getReportFiles(0);
			}
			else if(getReportVal == 0)
			{
				if(report_File.exists())
				{
					System.out.println("File already exists, therefore, delete.");	
					report_File.delete();
				}
				else
				{
					System.out.println("File doesn't exist, ...Issue!");
				}
			}
			
			
		}
		/*VIEW REPORT*/
		else if(f.getSource() == fightViewReportMenuItem)
		{
			String selectedFile = new String();
			selectedFile = reportList.getSelectedValue().toString();
			reportFrame.setTitle(selectedFile);
			reportFrame.setLayout(new BorderLayout (10,10));
			reportFrame.setSize(400,400);
			
			reportPanel.setLayout(new BorderLayout(10,10));
			reportPanel.setBorder(BorderFactory.createTitledBorder("Report view for " + selectedFile));
			//System.out.println(initLocation + "readMe");
				
			reportArea.setColumns(20);
			reportArea.setLineWrap(true);
			reportArea.setRows(5);
			reportArea.setWrapStyleWord(true);
			reportArea.setEditable(false);
			reportArea.setPreferredSize(getMaximumSize());	
			jScrollPaneRepoFrame.setViewportView(reportArea);
			
			reportArea.setLocation(0,0);
			reportPanel.add(jScrollPaneRepoFrame, BorderLayout.CENTER);
			reportArea.setVisible(true);
			
			File repo_File = new File(reportsPath + File.separator + selectedFile);
			fileChooser.setSelectedFile(repo_File);
			try 
			{
				reportArea.read( new FileReader( repo_File.getAbsolutePath() ), null );
				System.out.println("File Opened: ~" + repo_File.toString() + "~");
			}   
			catch (IOException ex) 
			{
				System.out.println("problem accessing file"+repo_File.getAbsolutePath());
			}
			
			reportFrame.add(reportPanel, BorderLayout.CENTER);
			reportFrame.setVisible(true);
		}
		/*DELETE REPORT*/
		else if(f.getSource() == fightDeleteReportMenuItem || f.getSource() == deleteButton)
		{
			String selectedFile = new String(reportList.getSelectedValue().toString());
			String reportFile = new String(reportsPath + File.separator + selectedFile);
			System.out.println(reportFile);
			File report_File = new File(reportFile);
			if(report_File.exists())
			{
				System.out.println("File already exists, therefore, delete.");	
				report_File.delete();
			}
			else
			{
				System.out.println("File doesn't exist, ...Issue!");
			}
			
			getReportFiles(1);
		}
		/*Iteration Limit*/
		else if(f.getSource() == fightIterationMenuItem)
		{
			String result = JOptionPane.showInputDialog(fightFrame, "What is the iteration limit?", "1");
			if((result != null) && (result.length() > 0))
			{
				System.out.println("Result = " + result + ".");
			}
			
			//iteration = Integer.parseInt(result);
			
			iteration = new String(result);
			
			System.out.println("Iteration = " + iteration + ".");
		}
		/*Vs1 - PVP2*/
		else if(f.getSource() == vs1)
		{
			pvp = 2;
		}
		/*Vs2 - PVP3*/
		else if(f.getSource() == vs2)
		{
			pvp = 3;
		}
		/*Vs3 - PVP4*/
		else if(f.getSource() == vs3)
		{
			pvp = 4;
		}
		
	}
	
	public void visualActionPerformed(ActionEvent v)
	{
		/*Show Visual*/
		if(v.getSource() == visualButton || v.getSource() == fightVisualMenuItem)
		{
			Painter = new paintLoop();
			
			for(int i = 0; i < 4096; i++)
			{
				ChangeColor(i,TMNT);
			}

			Painter.reportsPath = reportsPath;
			Painter.cdmG = this;
			Painter.flag = pop;
			Painter.speed = inital;
			Painter.reportList = reportList;
			Painter.start();
			
			visualButton.setEnabled(false);
			fightVisualMenuItem.setEnabled(false);
			
			String selectedFile = new String();
			selectedFile = reportList.getSelectedValue().toString();
			
			BufferedReader reader = null;
		//	String selectedFile = new String(reportList.getSelectedValue().toString());
			String reportFile = new String(reportsPath + File.separator + selectedFile);
			//System.out.println("Visual is looking in: "+reportFile);
			File report_File = new File(reportFile);
			
			try
			{
				String currentLine;
				String[] tokenArray = new String[50];
				int t = 0;
				int count = 0;
				
				reader = new BufferedReader(new FileReader(reportFile));
				
				while((currentLine = reader.readLine()) != null)
				{
					if(currentLine.contains("you..."))
					{
						tokenArray = currentLine.split(" ");
//						if(tokenArray[0].equals(">"))
//						{
							playerID = new String(tokenArray[1]);
							//System.out.println("playerID: "+ playerID);
							int length = tokenArray[3].length();
							codemonName = new String(tokenArray[3].substring(1,length-1));
							//System.out.println("codemonName: "+ codemonName);
//						}
						players[count] = playerID;
						codemons[count] = codemonName;
					}
					else if(currentLine.contains("Codex"))
					{
						tokenArray = currentLine.split(" ");
//						if(tokenArray[3].equals("Codex"))
//						{
							address = new String(tokenArray[6]);
							//System.out.println("Address: "+ address + "\n");
//						}
						adds[count] = address;
					}
					else if(currentLine.contains("lines"))
					{
						tokenArray = currentLine.split(" ");
						int length2 = tokenArray[2].length();
						lineToken = new String(tokenArray[2].substring(7));
						lines[count] = lineToken;
						
						System.out.println("players: "+ players[count]);
						System.out.println("codemons: "+ codemons[count]);
						System.out.println("adds: "+ adds[count]);
						System.out.println("lines: "+ lines[count]);
						System.out.println("count: "+ count + "\n");
						int addGet = 0;
						addGet = Integer.parseInt(adds[count]);
						int nLines = 0;
						nLines = Integer.parseInt(lines[count]);
						//System.out.println("Address is: " + addGet);
						if(count == 0)
						{
							ChangeColor(addGet, Michelangelo);
							for(int i = 0; i< nLines; i++)
							{
								ChangeColor(addGet+i,Michelangelo);
							}
							name1.setText(players[count]);
							lines1.setText(lines[count]);
						}
						else if(count == 1)
						{
							ChangeColor(addGet, Donatello);
							for(int i = 0; i< nLines; i++)
							{
								ChangeColor(addGet+i,Donatello);
							}
							
							name2.setText(players[count]);
							lines2.setText(lines[count]);
						}
						else if(count == 2)
						{
							ChangeColor(addGet, Raphael);
							for(int i = 0; i< nLines; i++)
							{
								ChangeColor(addGet+i,Raphael);
							}
							
							name3.setText(players[count]);
							lines3.setText(lines[count]);
						}
						else if(count == 3)
						{
							ChangeColor(addGet, Leonardo);
							for(int i = 0; i< nLines; i++)
							{
								ChangeColor(addGet+i,Leonardo);
							}
							name4.setText(players[count]);
							lines4.setText(lines[count]);
						}
						else
						{
							System.out.println("Error. Too many players\n\n");
						}
						
						count++;
					}
					
				}
				//System.out.println("SUGAR\n\n\n\n");
				
			}
			catch (IOException e)
			{
				System.out.println("Exception!");
				e.printStackTrace();
			}
			finally
			{
				try 
				{
					if (reader != null)reader.close();
					
				} 
				catch (IOException ex) 
				{
					System.out.println("Exception! Closing!");
					ex.printStackTrace();
				}
			}
			
			visualFrame.setVisible(true);
		}
		/*Play Pause*/
		else if(v.getSource() == play)
		{
			if(pop == 0)
			{
				/*Image Change*/
				play.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "play.png"));
				pop = 1;
				Painter.flag = 1;
				//System.out.println(pop);
				
				/*Action*/
			}
			else
			{
				/*Image Change*/
				play.setIcon(new ImageIcon(rootPath + File.separator + "images" + File.separator + "pause.png"));
				pop = 0;
				Painter.flag = 0;
				//System.out.println(pop);
				
				/*Action*/
			}
		}
		else if(v.getSource() == fast)
		{
			if(Painter.speed > 10)
			{
				Painter.speed = Painter.speed - increment;
			}
			else if(Painter.speed == 10)
			{
				Painter.speed = 5;
			}
			else if(Painter.speed == 5)
			{
				Painter.speed = 1;
			}
			System.out.println(Painter.speed);
		}
		else if(v.getSource() == slow)
		{
			if(Painter.speed == 1)
			{
				Painter.speed = 5;
			}
			else if(Painter.speed == 5)
			{
				Painter.speed = 10;
			}
			else if(Painter.speed < 550)
			{
				Painter.speed = Painter.speed + increment;	
			}
			System.out.println(Painter.speed);
		}
	}
	
	public static void main(String[] args)
	{
		codemonGui test = new codemonGui();
		test.setTitle("CodeMon: The Fight for 1 or 0");
		test.setSize(640,400);
		test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		test.setVisible(true);
	}
	
	
	
	
}