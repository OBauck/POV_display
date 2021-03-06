
#include "nrf.h"
#include "font.h"
/* 
**  Font data for Arial 8pt
*/

/* Character bitmaps for Arial 8pt */
const uint8_t arial_8ptBitmaps[] = 
{
	/* @0 '!' (2 pixels wide) */
	0x37, 0xC0, //   ## ##### 
	0x37, 0xC0, //   ## ##### 

	/* @4 '"' (5 pixels wide) */
	0x01, 0xC0, //        ### 
	0x01, 0xC0, //        ### 
	0x00, 0x00, //            
	0x01, 0xC0, //        ### 
	0x01, 0xC0, //        ### 

	/* @14 '#' (6 pixels wide) */
	0x39, 0x00, //   ###  #   
	0x0F, 0x00, //     ####   
	0x09, 0xC0, //     #  ### 
	0x39, 0x00, //   ###  #   
	0x0F, 0x00, //     ####   
	0x09, 0xC0, //     #  ### 

	/* @26 '$' (5 pixels wide) */
	0x13, 0x80, //    #  ###  
	0x26, 0x40, //   #  ##  # 
	0x7F, 0xE0, //  ##########
	0x26, 0x40, //   #  ##  # 
	0x1C, 0x80, //    ###  #  

	/* @36 '%' (8 pixels wide) */
	0x03, 0xC0, //       #### 
	0x02, 0x40, //       #  # 
	0x33, 0xC0, //   ##  #### 
	0x0C, 0x00, //     ##     
	0x03, 0x00, //       ##   
	0x3C, 0xC0, //   ####  ## 
	0x24, 0x00, //   #  #     
	0x3C, 0x00, //   ####     

	/* @52 '&' (7 pixels wide) */
	0x18, 0x00, //    ##      
	0x3D, 0x80, //   #### ##  
	0x27, 0xC0, //   #  ##### 
	0x26, 0x40, //   #  ##  # 
	0x3D, 0xC0, //   #### ### 
	0x39, 0x80, //   ###  ##  
	0x2C, 0x00, //   # ##     

	/* @66 ''' (2 pixels wide) */
	0x01, 0xC0, //        ### 
	0x01, 0xC0, //        ### 

	/* @70 '(' (3 pixels wide) */
	0x1F, 0x00, //    #####   
	0x7F, 0x80, //  ########  
	0xC0, 0xC0, // ##      ## 

	/* @76 ')' (3 pixels wide) */
	0xC0, 0x40, // ##       # 
	0x7F, 0x80, //  ########  
	0x1E, 0x00, //    ####    

	/* @82 '*' (3 pixels wide) */
	0x02, 0x80, //       # #  
	0x01, 0xC0, //        ### 
	0x02, 0x80, //       # #  

	/* @88 '+' (5 pixels wide) */
	0x04, 0x00, //      #     
	0x04, 0x00, //      #     
	0x1F, 0x00, //    #####   
	0x04, 0x00, //      #     
	0x04, 0x00, //      #     

	/* @98 ',' (2 pixels wide) */
	0xB0, 0x00, // # ##       
	0x70, 0x00, //  ###       

	/* @102 '-' (3 pixels wide) */
	0x08, 0x00, //     #      
	0x08, 0x00, //     #      
	0x08, 0x00, //     #      

	/* @108 '.' (2 pixels wide) */
	0x30, 0x00, //   ##       
	0x30, 0x00, //   ##       

	/* @112 '/' (3 pixels wide) */
	0x30, 0x00, //   ##       
	0x0F, 0x00, //     ####   
	0x00, 0xC0, //         ## 

	/* @118 '0' (5 pixels wide) */
	0x1F, 0x80, //    ######  
	0x3F, 0xC0, //   ######## 
	0x20, 0x40, //   #      # 
	0x3F, 0xC0, //   ######## 
	0x1F, 0x80, //    ######  

	/* @128 '1' (4 pixels wide) */
	0x03, 0x00, //       ##   
	0x01, 0x80, //        ##  
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @136 '2' (5 pixels wide) */
	0x30, 0x80, //   ##    #  
	0x38, 0xC0, //   ###   ## 
	0x2C, 0x40, //   # ##   # 
	0x27, 0xC0, //   #  ##### 
	0x23, 0x80, //   #   ###  

	/* @146 '3' (5 pixels wide) */
	0x10, 0x80, //    #    #  
	0x30, 0xC0, //   ##    ## 
	0x22, 0x40, //   #   #  # 
	0x3F, 0xC0, //   ######## 
	0x1D, 0x80, //    ### ##  

	/* @156 '4' (6 pixels wide) */
	0x0C, 0x00, //     ##     
	0x0B, 0x00, //     # ##   
	0x08, 0x80, //     #   #  
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x08, 0x00, //     #      

	/* @168 '5' (5 pixels wide) */
	0x17, 0x00, //    # ###   
	0x33, 0xC0, //   ##  #### 
	0x22, 0xC0, //   #   # ## 
	0x3E, 0x40, //   #####  # 
	0x1C, 0x40, //    ###   # 

	/* @178 '6' (5 pixels wide) */
	0x1F, 0x80, //    ######  
	0x3F, 0xC0, //   ######## 
	0x22, 0x40, //   #   #  # 
	0x3E, 0xC0, //   ##### ## 
	0x1C, 0x80, //    ###  #  

	/* @188 '7' (5 pixels wide) */
	0x00, 0x40, //          # 
	0x3C, 0x40, //   ####   # 
	0x3F, 0x40, //   ###### # 
	0x03, 0xC0, //       #### 
	0x00, 0xC0, //         ## 

	/* @198 '8' (5 pixels wide) */
	0x1D, 0x80, //    ### ##  
	0x3F, 0xC0, //   ######## 
	0x22, 0x40, //   #   #  # 
	0x3F, 0xC0, //   ######## 
	0x1D, 0x80, //    ### ##  

	/* @208 '9' (5 pixels wide) */
	0x13, 0x80, //    #  ###  
	0x37, 0xC0, //   ## ##### 
	0x24, 0x40, //   #  #   # 
	0x3F, 0xC0, //   ######## 
	0x1F, 0x80, //    ######  

	/* @218 ':' (2 pixels wide) */
	0x33, 0x00, //   ##  ##   
	0x33, 0x00, //   ##  ##   

	/* @222 ';' (2 pixels wide) */
	0xB3, 0x00, // # ##  ##   
	0x73, 0x00, //  ###  ##   

	/* @226 '<' (5 pixels wide) */
	0x06, 0x00, //      ##    
	0x06, 0x00, //      ##    
	0x09, 0x00, //     #  #   
	0x09, 0x00, //     #  #   
	0x10, 0x80, //    #    #  

	/* @236 '=' (5 pixels wide) */
	0x0A, 0x00, //     # #    
	0x0A, 0x00, //     # #    
	0x0A, 0x00, //     # #    
	0x0A, 0x00, //     # #    
	0x0A, 0x00, //     # #    

	/* @246 '>' (5 pixels wide) */
	0x10, 0x80, //    #    #  
	0x09, 0x00, //     #  #   
	0x09, 0x00, //     #  #   
	0x06, 0x00, //      ##    
	0x06, 0x00, //      ##    

	/* @256 '?' (5 pixels wide) */
	0x00, 0x80, //         #  
	0x34, 0xC0, //   ## #  ## 
	0x36, 0x40, //   ## ##  # 
	0x03, 0xC0, //       #### 
	0x01, 0x80, //        ##  

	/* @266 '@' (10 pixels wide) */
	0x1E, 0x00, //    ####    
	0x61, 0x80, //  ##    ##  
	0x5C, 0x80, //  # ###  #  
	0xA3, 0x40, // # #   ## # 
	0xA1, 0x40, // # #    # # 
	0xB1, 0x40, // # ##   # # 
	0xBF, 0x40, // # ###### # 
	0xA3, 0x40, // # #   ## # 
	0x50, 0x80, //  # #    #  
	0x4F, 0x00, //  #  ####   

	/* @286 'A' (7 pixels wide) */
	0x38, 0x00, //   ###      
	0x3F, 0x00, //   ######   
	0x0F, 0xC0, //     ###### 
	0x08, 0xC0, //     #   ## 
	0x0F, 0xC0, //     ###### 
	0x3F, 0x00, //   ######   
	0x38, 0x00, //   ###      

	/* @300 'B' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x22, 0x40, //   #   #  # 
	0x22, 0x40, //   #   #  # 
	0x3F, 0xC0, //   ######## 
	0x1D, 0x80, //    ### ##  

	/* @312 'C' (7 pixels wide) */
	0x0F, 0x00, //     ####   
	0x1F, 0x80, //    ######  
	0x30, 0xC0, //   ##    ## 
	0x20, 0x40, //   #      # 
	0x20, 0x40, //   #      # 
	0x30, 0xC0, //   ##    ## 
	0x10, 0x80, //    #    #  

	/* @326 'D' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x20, 0x40, //   #      # 
	0x20, 0x40, //   #      # 
	0x3F, 0xC0, //   ######## 
	0x1F, 0x80, //    ######  

	/* @338 'E' (5 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x22, 0x40, //   #   #  # 
	0x22, 0x40, //   #   #  # 
	0x22, 0x40, //   #   #  # 

	/* @348 'F' (5 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x02, 0x40, //       #  # 
	0x02, 0x40, //       #  # 
	0x02, 0x40, //       #  # 

	/* @358 'G' (7 pixels wide) */
	0x0F, 0x00, //     ####   
	0x1F, 0x80, //    ######  
	0x30, 0xC0, //   ##    ## 
	0x20, 0x40, //   #      # 
	0x24, 0x40, //   #  #   # 
	0x3C, 0xC0, //   ####  ## 
	0x1C, 0x80, //    ###  #  

	/* @372 'H' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x02, 0x00, //       #    
	0x02, 0x00, //       #    
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @384 'I' (2 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @388 'J' (5 pixels wide) */
	0x10, 0x00, //    #       
	0x30, 0x00, //   ##       
	0x20, 0x00, //   #        
	0x3F, 0xC0, //   ######## 
	0x1F, 0xC0, //    ####### 

	/* @398 'K' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x06, 0x00, //      ##    
	0x0F, 0x80, //     #####  
	0x3D, 0xC0, //   #### ### 
	0x30, 0x40, //   ##     # 

	/* @410 'L' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x20, 0x00, //   #        
	0x20, 0x00, //   #        
	0x20, 0x00, //   #        
	0x20, 0x00, //   #        

	/* @422 'M' (9 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x03, 0xC0, //       #### 
	0x1F, 0x00, //    #####   
	0x38, 0x00, //   ###      
	0x1F, 0x00, //    #####   
	0x03, 0xC0, //       #### 
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @440 'N' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x03, 0x00, //       ##   
	0x0C, 0x00, //     ##     
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @452 'O' (7 pixels wide) */
	0x0F, 0x00, //     ####   
	0x1F, 0x80, //    ######  
	0x30, 0xC0, //   ##    ## 
	0x20, 0x40, //   #      # 
	0x30, 0xC0, //   ##    ## 
	0x1F, 0x80, //    ######  
	0x0F, 0x00, //     ####   

	/* @466 'P' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x04, 0x40, //      #   # 
	0x04, 0x40, //      #   # 
	0x07, 0xC0, //      ##### 
	0x03, 0x80, //       ###  

	/* @478 'Q' (7 pixels wide) */
	0x0F, 0x00, //     ####   
	0x1F, 0x80, //    ######  
	0x30, 0xC0, //   ##    ## 
	0x28, 0x40, //   # #    # 
	0x30, 0xC0, //   ##    ## 
	0x3F, 0x80, //   #######  
	0x4F, 0x00, //  #  ####   

	/* @492 'R' (7 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x04, 0x40, //      #   # 
	0x0C, 0x40, //     ##   # 
	0x1F, 0xC0, //    ####### 
	0x33, 0x80, //   ##  ###  
	0x20, 0x00, //   #        

	/* @506 'S' (6 pixels wide) */
	0x13, 0x80, //    #  ###  
	0x33, 0xC0, //   ##  #### 
	0x26, 0x40, //   #  ##  # 
	0x26, 0x40, //   #  ##  # 
	0x3C, 0xC0, //   ####  ## 
	0x1C, 0x80, //    ###  #  

	/* @518 'T' (6 pixels wide) */
	0x00, 0x40, //          # 
	0x00, 0x40, //          # 
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x00, 0x40, //          # 
	0x00, 0x40, //          # 

	/* @530 'U' (6 pixels wide) */
	0x1F, 0xC0, //    ####### 
	0x3F, 0xC0, //   ######## 
	0x20, 0x00, //   #        
	0x20, 0x00, //   #        
	0x3F, 0xC0, //   ######## 
	0x1F, 0xC0, //    ####### 

	/* @542 'V' (7 pixels wide) */
	0x00, 0xC0, //         ## 
	0x0F, 0xC0, //     ###### 
	0x3F, 0x00, //   ######   
	0x30, 0x00, //   ##       
	0x3F, 0x00, //   ######   
	0x0F, 0xC0, //     ###### 
	0x00, 0xC0, //         ## 

	/* @556 'W' (11 pixels wide) */
	0x00, 0xC0, //         ## 
	0x0F, 0xC0, //     ###### 
	0x3F, 0x00, //   ######   
	0x38, 0x00, //   ###      
	0x0F, 0x80, //     #####  
	0x01, 0xC0, //        ### 
	0x0F, 0x80, //     #####  
	0x38, 0x00, //   ###      
	0x3F, 0x00, //   ######   
	0x0F, 0xC0, //     ###### 
	0x00, 0xC0, //         ## 

	/* @578 'X' (6 pixels wide) */
	0x30, 0xC0, //   ##    ## 
	0x39, 0xC0, //   ###  ### 
	0x0F, 0x00, //     ####   
	0x0F, 0x00, //     ####   
	0x39, 0xC0, //   ###  ### 
	0x30, 0xC0, //   ##    ## 

	/* @590 'Y' (6 pixels wide) */
	0x00, 0xC0, //         ## 
	0x03, 0xC0, //       #### 
	0x3E, 0x00, //   #####    
	0x3E, 0x00, //   #####    
	0x03, 0xC0, //       #### 
	0x00, 0xC0, //         ## 

	/* @602 'Z' (6 pixels wide) */
	0x30, 0x40, //   ##     # 
	0x38, 0x40, //   ###    # 
	0x2E, 0x40, //   # ###  # 
	0x27, 0x40, //   #  ### # 
	0x21, 0xC0, //   #    ### 
	0x20, 0xC0, //   #     ## 

	/* @614 '[' (3 pixels wide) */
	0xFF, 0xC0, // ########## 
	0xFF, 0xC0, // ########## 
	0x80, 0x40, // #        # 

	/* @620 '\' (3 pixels wide) */
	0x00, 0xC0, //         ## 
	0x0F, 0x00, //     ####   
	0x30, 0x00, //   ##       

	/* @626 ']' (3 pixels wide) */
	0x80, 0x40, // #        # 
	0xFF, 0xC0, // ########## 
	0xFF, 0xC0, // ########## 

	/* @632 '^' (5 pixels wide) */
	0x02, 0x00, //       #    
	0x03, 0x80, //       ###  
	0x00, 0xC0, //         ## 
	0x03, 0x80, //       ###  
	0x02, 0x00, //       #    

	/* @642 '_' (6 pixels wide) */
	0x80, 0x00, // #          
	0x80, 0x00, // #          
	0x80, 0x00, // #          
	0x80, 0x00, // #          
	0x80, 0x00, // #          
	0x80, 0x00, // #          

	/* @654 '`' (3 pixels wide) */
	0x00, 0x40, //          # 
	0x00, 0xC0, //         ## 
	0x00, 0x80, //         #  

	/* @660 'a' (5 pixels wide) */
	0x1A, 0x00, //    ## #    
	0x3D, 0x00, //   #### #   
	0x25, 0x00, //   #  # #   
	0x3F, 0x00, //   ######   
	0x3E, 0x00, //   #####    

	/* @670 'b' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x21, 0x00, //   #    #   
	0x21, 0x00, //   #    #   
	0x3F, 0x00, //   ######   
	0x1E, 0x00, //    ####    

	/* @682 'c' (5 pixels wide) */
	0x1E, 0x00, //    ####    
	0x3F, 0x00, //   ######   
	0x21, 0x00, //   #    #   
	0x33, 0x00, //   ##  ##   
	0x12, 0x00, //    #  #    

	/* @692 'd' (6 pixels wide) */
	0x1E, 0x00, //    ####    
	0x3F, 0x00, //   ######   
	0x21, 0x00, //   #    #   
	0x21, 0x00, //   #    #   
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @704 'e' (6 pixels wide) */
	0x1E, 0x00, //    ####    
	0x3F, 0x00, //   ######   
	0x25, 0x00, //   #  # #   
	0x25, 0x00, //   #  # #   
	0x37, 0x00, //   ## ###   
	0x16, 0x00, //    # ##    

	/* @716 'f' (5 pixels wide) */
	0x01, 0x00, //        #   
	0x3F, 0x80, //   #######  
	0x3F, 0xC0, //   ######## 
	0x01, 0x40, //        # # 
	0x00, 0x40, //          # 

	/* @726 'g' (6 pixels wide) */
	0x5E, 0x00, //  # ####    
	0xBF, 0x00, // # ######   
	0xA1, 0x00, // # #    #   
	0xA1, 0x00, // # #    #   
	0xFF, 0x00, // ########   
	0x7F, 0x00, //  #######   

	/* @738 'h' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x01, 0x00, //        #   
	0x01, 0x00, //        #   
	0x3F, 0x00, //   ######   
	0x3E, 0x00, //   #####    

	/* @750 'i' (2 pixels wide) */
	0x3F, 0x40, //   ###### # 
	0x3F, 0x40, //   ###### # 

	/* @754 'j' (3 pixels wide) */
	0x80, 0x00, // #          
	0xFF, 0x40, // ######## # 
	0x7F, 0x40, //  ####### # 

	/* @760 'k' (6 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 
	0x0C, 0x00, //     ##     
	0x1E, 0x00, //    ####    
	0x3B, 0x00, //   ### ##   
	0x21, 0x00, //   #    #   

	/* @772 'l' (2 pixels wide) */
	0x3F, 0xC0, //   ######## 
	0x3F, 0xC0, //   ######## 

	/* @776 'm' (10 pixels wide) */
	0x3F, 0x00, //   ######   
	0x3F, 0x00, //   ######   
	0x01, 0x00, //        #   
	0x01, 0x00, //        #   
	0x3F, 0x00, //   ######   
	0x3F, 0x00, //   ######   
	0x01, 0x00, //        #   
	0x01, 0x00, //        #   
	0x3F, 0x00, //   ######   
	0x3E, 0x00, //   #####    

	/* @796 'n' (6 pixels wide) */
	0x3F, 0x00, //   ######   
	0x3F, 0x00, //   ######   
	0x01, 0x00, //        #   
	0x01, 0x00, //        #   
	0x3F, 0x00, //   ######   
	0x3E, 0x00, //   #####    

	/* @808 'o' (6 pixels wide) */
	0x1E, 0x00, //    ####    
	0x3F, 0x00, //   ######   
	0x21, 0x00, //   #    #   
	0x21, 0x00, //   #    #   
	0x3F, 0x00, //   ######   
	0x1E, 0x00, //    ####    

	/* @820 'p' (6 pixels wide) */
	0xFF, 0x00, // ########   
	0xFF, 0x00, // ########   
	0x21, 0x00, //   #    #   
	0x21, 0x00, //   #    #   
	0x3F, 0x00, //   ######   
	0x1E, 0x00, //    ####    

	/* @832 'q' (6 pixels wide) */
	0x1E, 0x00, //    ####    
	0x3F, 0x00, //   ######   
	0x21, 0x00, //   #    #   
	0x21, 0x00, //   #    #   
	0xFF, 0x00, // ########   
	0xFF, 0x00, // ########   

	/* @844 'r' (4 pixels wide) */
	0x3F, 0x00, //   ######   
	0x3F, 0x00, //   ######   
	0x01, 0x00, //        #   
	0x01, 0x00, //        #   

	/* @852 's' (6 pixels wide) */
	0x16, 0x00, //    # ##    
	0x37, 0x00, //   ## ###   
	0x2D, 0x00, //   # ## #   
	0x2D, 0x00, //   # ## #   
	0x3B, 0x00, //   ### ##   
	0x1A, 0x00, //    ## #    

	/* @864 't' (4 pixels wide) */
	0x01, 0x00, //        #   
	0x1F, 0x80, //    ######  
	0x3F, 0xC0, //   ######## 
	0x21, 0x00, //   #    #   

	/* @872 'u' (6 pixels wide) */
	0x1F, 0x00, //    #####   
	0x3F, 0x00, //   ######   
	0x20, 0x00, //   #        
	0x20, 0x00, //   #        
	0x3F, 0x00, //   ######   
	0x3F, 0x00, //   ######   

	/* @884 'v' (5 pixels wide) */
	0x0F, 0x00, //     ####   
	0x3F, 0x00, //   ######   
	0x30, 0x00, //   ##       
	0x3F, 0x00, //   ######   
	0x0F, 0x00, //     ####   

	/* @894 'w' (9 pixels wide) */
	0x07, 0x00, //      ###   
	0x3F, 0x00, //   ######   
	0x38, 0x00, //   ###      
	0x1E, 0x00, //    ####    
	0x07, 0x00, //      ###   
	0x1E, 0x00, //    ####    
	0x38, 0x00, //   ###      
	0x3F, 0x00, //   ######   
	0x07, 0x00, //      ###   

	/* @912 'x' (5 pixels wide) */
	0x33, 0x00, //   ##  ##   
	0x3F, 0x00, //   ######   
	0x0C, 0x00, //     ##     
	0x3F, 0x00, //   ######   
	0x33, 0x00, //   ##  ##   

	/* @922 'y' (7 pixels wide) */
	0x81, 0x00, // #      #   
	0x8F, 0x00, // #   ####   
	0xFE, 0x00, // #######    
	0x70, 0x00, //  ###       
	0x3E, 0x00, //   #####    
	0x0F, 0x00, //     ####   
	0x01, 0x00, //        #   

	/* @936 'z' (5 pixels wide) */
	0x31, 0x00, //   ##   #   
	0x39, 0x00, //   ###  #   
	0x2D, 0x00, //   # ## #   
	0x27, 0x00, //   #  ###   
	0x23, 0x00, //   #   ##   

	/* @946 '{' (4 pixels wide) */
	0x08, 0x00, //     #      
	0x7F, 0x80, //  ########  
	0xF7, 0xC0, // #### ##### 
	0x80, 0x40, // #        # 

	/* @954 '|' (1 pixels wide) */
	0xFF, 0xC0, // ########## 

	/* @956 '}' (4 pixels wide) */
	0x80, 0x40, // #        # 
	0xF7, 0xC0, // #### ##### 
	0x7F, 0x80, //  ########  
	0x08, 0x00, //     #      

	/* @964 '~' (5 pixels wide) */
	0x04, 0x00, //      #     
	0x02, 0x00, //       #    
	0x02, 0x00, //       #    
	0x04, 0x00, //      #     
	0x02, 0x00, //       #    
};

/* Character descriptors for Arial 8pt */
/* { [Char width in bits], [Offset into arial_8ptCharBitmaps in bytes] } */
const font_char_info_t arial_8ptDescriptors[] = 
{
	{2, 0}, 		/* ! */ 
	{5, 4}, 		/* " */ 
	{6, 14}, 		/* # */ 
	{5, 26}, 		/* $ */ 
	{8, 36}, 		/* % */ 
	{7, 52}, 		/* & */ 
	{2, 66}, 		/* ' */ 
	{3, 70}, 		/* ( */ 
	{3, 76}, 		/* ) */ 
	{3, 82}, 		/* * */ 
	{5, 88}, 		/* + */ 
	{2, 98}, 		/* , */ 
	{3, 102}, 		/* - */ 
	{2, 108}, 		/* . */ 
	{3, 112}, 		/* / */ 
	{5, 118}, 		/* 0 */ 
	{4, 128}, 		/* 1 */ 
	{5, 136}, 		/* 2 */ 
	{5, 146}, 		/* 3 */ 
	{6, 156}, 		/* 4 */ 
	{5, 168}, 		/* 5 */ 
	{5, 178}, 		/* 6 */ 
	{5, 188}, 		/* 7 */ 
	{5, 198}, 		/* 8 */ 
	{5, 208}, 		/* 9 */ 
	{2, 218}, 		/* : */ 
	{2, 222}, 		/* ; */ 
	{5, 226}, 		/* < */ 
	{5, 236}, 		/* = */ 
	{5, 246}, 		/* > */ 
	{5, 256}, 		/* ? */ 
	{10, 266}, 		/* @ */ 
	{7, 286}, 		/* A */ 
	{6, 300}, 		/* B */ 
	{7, 312}, 		/* C */ 
	{6, 326}, 		/* D */ 
	{5, 338}, 		/* E */ 
	{5, 348}, 		/* F */ 
	{7, 358}, 		/* G */ 
	{6, 372}, 		/* H */ 
	{2, 384}, 		/* I */ 
	{5, 388}, 		/* J */ 
	{6, 398}, 		/* K */ 
	{6, 410}, 		/* L */ 
	{9, 422}, 		/* M */ 
	{6, 440}, 		/* N */ 
	{7, 452}, 		/* O */ 
	{6, 466}, 		/* P */ 
	{7, 478}, 		/* Q */ 
	{7, 492}, 		/* R */ 
	{6, 506}, 		/* S */ 
	{6, 518}, 		/* T */ 
	{6, 530}, 		/* U */ 
	{7, 542}, 		/* V */ 
	{11, 556}, 		/* W */ 
	{6, 578}, 		/* X */ 
	{6, 590}, 		/* Y */ 
	{6, 602}, 		/* Z */ 
	{3, 614}, 		/* [ */ 
	{3, 620}, 		/* \ */ 
	{3, 626}, 		/* ] */ 
	{5, 632}, 		/* ^ */ 
	{6, 642}, 		/* _ */ 
	{3, 654}, 		/* ` */ 
	{5, 660}, 		/* a */ 
	{6, 670}, 		/* b */ 
	{5, 682}, 		/* c */ 
	{6, 692}, 		/* d */ 
	{6, 704}, 		/* e */ 
	{5, 716}, 		/* f */ 
	{6, 726}, 		/* g */ 
	{6, 738}, 		/* h */ 
	{2, 750}, 		/* i */ 
	{3, 754}, 		/* j */ 
	{6, 760}, 		/* k */ 
	{2, 772}, 		/* l */ 
	{10, 776}, 		/* m */ 
	{6, 796}, 		/* n */ 
	{6, 808}, 		/* o */ 
	{6, 820}, 		/* p */ 
	{6, 832}, 		/* q */ 
	{4, 844}, 		/* r */ 
	{6, 852}, 		/* s */ 
	{4, 864}, 		/* t */ 
	{6, 872}, 		/* u */ 
	{5, 884}, 		/* v */ 
	{9, 894}, 		/* w */ 
	{5, 912}, 		/* x */ 
	{7, 922}, 		/* y */ 
	{5, 936}, 		/* z */ 
	{4, 946}, 		/* { */ 
	{1, 954}, 		/* | */ 
	{4, 956}, 		/* } */ 
	{5, 964}, 		/* ~ */ 
};

/* Font information for Arial 8pt */
const font_info_t arial_8ptFontInfo =
{
	11, /*  Character height */
	'!', /*  Start character */
	'~', /*  End character */
	2, /*  Width, in pixels, of space character */
	arial_8ptDescriptors, /*  Character descriptor array */
	arial_8ptBitmaps, /*  Character bitmap array */
};

