

// trip recoder testing 2014.10.16

	// TripDataPoint = 9;
	I2CA_WriteData(ADDR_24LC32, EPROM_ADDR_TRIP_POINT, 9);

	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.START_TIME,gStr1,20);

//--- trip recoder 0
	TripInfoNow.CODE = 0;
	TripInfoNow.CURRENT = 0.0;
	TripInfoNow.DATA = 0.0;
	TripInfoNow.VDC = 0.0;
	TripInfoNow.VOUT = 0.0;

	strncpy(TripInfoNow.MSG  ,"trip recoder 0",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );

//--- trip recoder 1
	strncpy(TripInfoNow.MSG  ,"trip recoder 1",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 2
	strncpy(TripInfoNow.MSG  ,"trip recoder 2",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 3
	strncpy(TripInfoNow.MSG  ,"trip recoder 3",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 4
	strncpy(TripInfoNow.MSG  ,"trip recoder 4",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 5
	strncpy(TripInfoNow.MSG  ,"trip recoder 5",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 6
	strncpy(TripInfoNow.MSG  ,"trip recoder 6",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 7
	strncpy(TripInfoNow.MSG  ,"trip recoder 7",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 8
	strncpy(TripInfoNow.MSG  ,"trip recoder 8",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );
//--- trip recoder 9
	strncpy(TripInfoNow.MSG  ,"trip recoder 9",20);
	GetTimeAndDateStr(gStr1);
	strncpy( TripInfoNow.TIME,gStr1,20);
	SaveTripDataToEeprom(  );

	for( i= 0 ; i < 10 ; i ++ ){ 
	    TripData = (TRIP_INFO*)malloc(sizeof(TRIP_INFO));
	    GetTripInfo(i,TripData);
		Nop();
		free(TripData);
	}

