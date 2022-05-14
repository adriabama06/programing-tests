package es.protector.events;

import es.protector.Main;
import es.protector.Util;
import es.protector.config.Config;
import org.bukkit.Location;
import org.bukkit.World;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.entity.EntityDamageEvent;

public class AntiHeal implements Listener {
    private Main plugin;

    public AntiHeal(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public void onHealChange(EntityDamageEvent event){
        if(!(event.getEntity() instanceof Player)) {
            return;
        }
        Player p = (Player) event.getEntity();

        if(p != null) {
            if(!Config.GetProtect().getStringList("enabledlocations").isEmpty()) {
                for(String areaname : Config.GetProtect().getStringList("enabledlocations")) {
                    if(!Config.GetProtect().getBoolean("locations." + areaname + ".antidamage")) {
                        continue;
                    }
                    double x1 = Config.GetProtect().getDouble("locations." + areaname + ".x1");
                    double y1 = Config.GetProtect().getDouble("locations." + areaname + ".y1");
                    double z1 = Config.GetProtect().getDouble("locations." + areaname + ".z1");

                    double x2 = Config.GetProtect().getDouble("locations." + areaname + ".x2");
                    double y2 = Config.GetProtect().getDouble("locations." + areaname + ".y2");
                    double z2 = Config.GetProtect().getDouble("locations." + areaname + ".z2");

                    World world = plugin.getServer().getWorld(Config.GetProtect().getString("locations." + areaname + ".world"));

                    if(Util.PlayerIsIn(p.getLocation(), new Location(world, x1, y1, z1), new Location(world, x2, y2, z2))) {
                        event.setCancelled(true);
                        p.setHealth(20.0);
                        break;
                    }
                }
            }
        }
    }
}
